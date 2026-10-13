#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Kalkulacka {
    public:
        int scitaj(int a,int b){
            return a + b; 
        }
        
        int odcitaj(int a,int b){
            return a - b; 
        }
        
        int nasob(int a,int b){
            return a * b; 
        }

        int del(int a,int b){
            if (b!=0){
                return a / b;
            } else {
                cout << "chyba pri deleni nulou" << endl;
                return 0;
            }
        }
        int mocnina(int a,int b) {
            int temp = 1;
            for (int i = 1; i <= b; i++) {
                temp *= a;
            }
            return temp;
        }

    int spravVypocet(int a,char operacia,int b) {
        int vysledok = 0;

        if (operacia == '+') {
            vysledok = scitaj(a, b);
        } else if (operacia == '-') {
            vysledok = odcitaj(a, b);
        } else if (operacia == '*') {
            vysledok = nasob(a, b);
        } else if (operacia == '/') {
            vysledok = del(a, b);
        } else if (operacia == '^') {
            vysledok = mocnina(a, b);
        } else {
            cout << "Neznamy operator!" << endl;
            return 0;
        }
        return vysledok;
    }
};


class ProgKalk : public Kalkulacka {
    private:
        int a_dec = 0;
        int b_dec = 0;
    
        void bin_to_dec(string &bin_a,string &bin_b) {
            a_dec = stoi(bin_a, nullptr, 2);
            b_dec = stoi(bin_b, nullptr, 2);
        }
    
        string dec_to_bin (int cislo) {
            if (cislo == 0) return "0";
    
                bool jeZaporne = false;
            if (cislo < 0) {
                jeZaporne = true;
                cislo = -cislo; // Zmeníme na kladné pre výpočet
            }
    
            string bin_a ="";
            while (cislo > 0) {
                bin_a = to_string(cislo % 2) + bin_a;
                cislo /= 2;
               }
    
            if (jeZaporne) {
                bin_a = "-" + bin_a;
            }
    
            return bin_a;
        }

        void dec_to_bin(string &bin_a, string &bin_b) {
            bin_a = dec_to_bin(a_dec);
            bin_b = dec_to_bin(b_dec);
        }
    public:


    ///////toto som nahradil dvoma funkciami vyssie, lebo potrebujem vediet konvertovat aj iba jedno cislo a to vysledok./////////
    // void dec_to_bin(int a_dec, int b_dec,string &bin_a, string &bin_b) {
    //     bin_a = "";
    //     bin_b = "";
    //     while (a_dec > 0) {
    //         bin_a = to_string(a_dec % 2) + bin_a;
    //         a_dec /= 2;
    //     }
    //     while (b_dec > 0) {
    //         bin_b = to_string(b_dec % 2) + bin_b;
    //         b_dec /= 2;
    //     }
    // }

    int spravPrepocet(string &bin_a, char operacia, string &bin_b) {
        bin_to_dec(bin_a, bin_b);
        int vysledok = spravVypocet(a_dec, operacia, b_dec);
        string vysledoks = dec_to_bin(vysledok);
        cout << "v 2kovej sustave: " <<bin_a << operacia << bin_b << " = " << vysledoks << endl;
        return vysledok;
    }

    int get_a_dec() {
        return a_dec;
    }
    int get_b_dec() {
        return b_dec;
    }
};



class SciKalk : public Kalkulacka {
    private:
    const double PI = acos(-1.0);
    public:
    float vypocitajgon(string goniometrickafunkcia,float &stupne) {
        float rad = stupne * (PI / 180.0f);
        if (goniometrickafunkcia=="sin"){
            return sin(rad);
        }
        else if (goniometrickafunkcia=="cos"){
            return cos(rad);
        }
        else if (goniometrickafunkcia=="tan"){
            return tan(rad);
        }
        cout << "Neznama funkcia";
        return 0;
    }
};



int main (){
    char operacia;
    float volba;


    while (true)
    {
        cout << "/////////////Menu://////////////" << endl;
        cout << "1. klasicka Kalkulacka" << endl;
        cout << "2. Programatorska kalkulacka " << endl;
        cout << "3. Vedecka kalkulacka " << endl;
        cout << "0. Ukoncit program" << endl;
        cin >> volba;

        if (volba == 0) {
            cout << "Dovidenia!" << endl;
            break;
        }

        else if (volba == 1){
            int a,b;
            Kalkulacka k;

            cout << "pouzivam klasicku kalkulacku" << endl;
            cout << "napis priklad v tvare (5+3)" << endl;
            cin >> a >> operacia >> b;

            int vysledok = k.spravVypocet(a, operacia, b);
            cout << "Vysledok: " << a << operacia << b << " = " << vysledok << endl;
        }
        
        else if (volba == 2) {
            ProgKalk progk;
            string bin_a;
            string bin_b;
            
            cout << "pouzivam programatorsku kalkulacku" << endl;
            cout << "napis priklad v tvare (101/n +/n 11/n)" << endl;
            cin >> bin_a >> operacia >> bin_b;

            int vysledok = progk.spravPrepocet(bin_a,operacia,bin_b);
            cout << "v 10tkovej sustave: " << progk.get_a_dec() << operacia << progk.get_b_dec() << " = " << vysledok << endl;
            
        }

        else if (volba==3) {
            string goniometrickafunkcia;
            float stupne;
            SciKalk vedk;

            cout << "pouzivam vedecku kalkulacku" << endl;
            cout << "napis priklad v tvare (sin /n 45(stupnov))" << endl;
            cin >> goniometrickafunkcia >> stupne;
            cout << goniometrickafunkcia << "(" << stupne << "):" << endl;
            cout << vedk.vypocitajgon(goniometrickafunkcia,stupne)<< endl;
        }
    }
}