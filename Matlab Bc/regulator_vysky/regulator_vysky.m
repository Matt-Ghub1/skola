function regulator_vysky(mode)
% REGULATOR_VYSKY  jednoduchy PID regulator vysky cez seriovu linku
%   regulator_vysky("hover") - pomaly zvysuje PWM a hlada, kedy sa vrtula zdvihne
%   regulator_vysky("let")   - vzlet -> drzanie -> pristatie -> motor stop
%
% Firmver v Arduine sa NEMENI. Arduino kazdych ~20 ms posle riadok
%   EC,PWM,vyska[mm],vyska[mm]
% a prijme prikaz "<cislo>x" (PWM 1000..2000).
%
% Je to funkcia (nie script) zamerne: onCleanup potom zastavi motor aj pri
% chybe alebo Ctrl+C.

if nargin < 1, mode = "let"; end
mode = string(mode);

%% ---------- PARAMETRE (ZMENIT PODLA ZARIADENIA) ----------
portName = "COM3";       % port Arduina (Spravca zariadeni)
Ts       = 0.02;         % perioda [s] (RolloverThreshold = 10 -> 20 ms)

uHover   = 1300;         % PWM, pri ktorom sa vznasa  <-- ZMERAT (mode "hover")
uMin     = 1000;         % dolny limit PWM
uMax     = 1350;         % horny limit PWM (drzat len kúsok nad uHover!)

Kp = 0.3;                % [us/mm]
Ki = 0.05;               % [us/(mm*s)]
Kd = 0.15;               % [us/(mm/s)]
Imax = 80;               % limit integracnej zlozky [us] (anti-windup)

hTarget = 300;           % ciel [mm]
vUp     = 50;            % rychlost vzletu [mm/s]
vDown   = 40;            % rychlost pristavania [mm/s]
tHold   = 10;            % dlzka drzania [s]
hEndMargin = 25;         % mm nad zaciatocnou vyskou -> vypnut motor

hMax = 600;              % bezpecnostny limit vysky [mm]
tMax = 90;               % max. dlzka pokusu [s]

% parametre hladania hoveru
uStart = 1100; uStep = 5; tStep = 1.5; uLimit = 1400; rise = 40;

%% ---------- PRIPOJENIE ----------
s = serialport(portName, 115200, "Timeout", 1);
configureTerminator(s, "CR/LF");
cleanup = onCleanup(@() stopMotor(s)); %#ok<NASGU>

disp("Cakam na Arduino (po otvoreni portu sa resetuje, rele ~10 s)...");
tWait = tic; buf = [];
while numel(buf) < 25
    if toc(tWait) > 40, error("Arduino neposiela data (senzor? port?)."); end
    v = readLine(s);
    if numel(v) == 4 && v(3) > 0 && v(3) < 4000
        buf(end+1) = v(3); %#ok<AGROW>
    end
end
y0 = median(buf);                       % vyska na zaciatku (na zemi)
fprintf("Zaciatocna vyska: %.0f mm\n", y0);

%% ---------- HLAVNA SLUCKA ----------
phase = 1;                              % 1 vzlet, 2 drzanie, 3 pristatie
r = y0; yf = y0; yfPrev = y0; yLast = y0; I = 0; u = uMin;
tPhase = tic; tStart = tic; tLastOk = tic;
logd = zeros(0,5);                      % [t r y u yf]
fname = "meranie_" + mode + "_" + string(datetime("now","Format","yyyyMMdd_HHmmss")) + ".mat";

while true
    v = readLine(s);
    if numel(v) ~= 4
        if toc(tLastOk) > 1, warning("Vypadok dat - zastavujem."); break, end
        continue
    end
    tLastOk = tic;

    y = v(3);
    if y <= 0 || y > 4000, y = yLast; end    % chybne meranie ToF
    yLast = y;
    yf = 0.7*yf + 0.3*y;                     % jednoduchy filter sumu
    t  = toc(tStart);

    if y > hMax || t > tMax, break, end      % bezpecnostne konce

    if mode == "hover"
        % --- postupne zvysovanie PWM ---
        u = min(uStart + uStep*floor(t/tStep), uLimit);
        r = y0;
        if yf > y0 + rise
            fprintf("Vrtula sa zdvihla pri PWM = %d us\n", u); break
        end
        if u >= uLimit, disp("Dosiahnuty uLimit, vrtula sa nezdvihla."); break, end
    else
        % --- plánovac ziadanej vysky ---
        switch phase
            case 1
                r = min(r + vUp*Ts, hTarget);
                if r >= hTarget, phase = 2; tPhase = tic; end
            case 2
                if toc(tPhase) > tHold, phase = 3; end
            case 3
                r = max(r - vDown*Ts, y0);
                if y <= y0 + hEndMargin, break, end
        end
        % --- PID ---
        e  = r - y;
        dy = (yf - yfPrev)/Ts;               % derivacia z merania (nie z chyby)
        I  = I + Ki*e*Ts;
        I  = min(max(I, -Imax), Imax);
        u  = uHover + Kp*e + I - Kd*dy;
        u  = min(max(u, uMin), uMax);
    end
    yfPrev = yf;

    u = round(u);
    write(s, sprintf('%dx', u), "char");
    logd(end+1,:) = [t r y u yf]; %#ok<AGROW>
    if mod(size(logd,1), 100) == 0, save(fname, "logd"); end   % priebezne ulozenie (~kazde 2 s)
end

stopMotor(s);

%% ---------- VYSLEDKY ----------
if ~isempty(logd)
    save(fname, "logd");
    fprintf("Ulozene: %s\n", fname);
    figure
    subplot(2,1,1)
    plot(logd(:,1), logd(:,2), "k--", logd(:,1), logd(:,3), "b"), grid on
    ylabel("vyska [mm]"), legend("ziadana","namerana")
    subplot(2,1,2)
    plot(logd(:,1), logd(:,4), "r"), grid on
    xlabel("cas [s]"), ylabel("PWM [us]")
    fprintf("Priemerna perioda: %.1f ms\n", 1000*mean(diff(logd(:,1))));
end
end

%% ---------- POMOCNE FUNKCIE ----------
function v = readLine(s)
% precita jeden riadok a vrati cisla; pri chybe/stavovej sprave vrati []
line = readline(s);
if isempty(line), v = []; return, end
v = str2double(split(line, ","));
if any(isnan(v)), v = []; end
end

function stopMotor(s)
try
    write(s, "1000x", "char");
    pause(0.2);
catch
end
end
