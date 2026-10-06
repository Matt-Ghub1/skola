#include <iostream>
#include <string>
using namespace std;

class Kalkulacky {
    private:
        int scitacia_pamat = 0;
        int posledny_vysledok =0;
    
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

        posledny_vysledok = vysledok;
        scitacia_pamat += vysledok;

        return vysledok;
    }
    int getPamat() {
        return scitacia_pamat;
    }

};

// moj kod z predosleho zadania ktory som upravil na metody vyssie

    //  int kalkulator(int cislo1, char oper, int cislo2) {
    // if (oper == '+') {
    //     vysledok = cislo1 + cislo2;
    // }
    // else if (oper == '-') {
    //     vysledok = cislo1 - cislo2;
    // }
    // else if (oper == '*') {
    //     vysledok = cislo1 * cislo2;
    // }
    // else if (oper == '/') {
    //     vysledok = cislo1 / cislo2;
    // }
    // else if (oper == '^') {
    //     vysledok = 1;
    //     for (int i = 1; i <= cislo2; i++) {
    //         vysledok *= cislo1;
    //     }
    // }
    // scitacia_pamat += vysledok;
    // return vysledok;
//}
    
class Predajna {
    private:
        Kalkulacky Kalkulacka[3];


    public:
        int pouziKalkulacku(int cisloKalkulacky, int a, char operacia, int b) {
            return Kalkulacka[cisloKalkulacky-1].spravVypocet(a, operacia, b);          //odcitam 1 lebo polia sa indexuju od 0
        }
        int getTrzbaPokladne(int cisloKalkulacky) {
            return Kalkulacka[cisloKalkulacky-1].getPamat();
        }
        int getCelkovaTrzba(){
            int celkovaTrzba = 0;
            for (int i = 0; i <= 2; i++)             //kedze polia sa indexuju od 0 tak idem Kalkulacka[0],Kalkulacka[1],Kalkulacka[2]
            {
                celkovaTrzba += Kalkulacka[i].getPamat();
            }
            return celkovaTrzba;
        }
            

};

int main() {
    Predajna predajna;
    int volba;

    
        while (true) {
        cout << "/////////////Menu://////////////" << endl;
        cout << "1. Pouzit kalkulacku (1, 2 alebo 3)" << endl;
        cout << "2. Zobrazit trzbu konkretnej pokladne" << endl;
        cout << "3. Zobrazit celkovu uzavierku predajne" << endl;
        cout << "0. Ukoncit program" << endl;
        cin >> volba;

        if (volba == 0) {
            cout << "Dovidenia :D" << endl;
            break;
        }
        else if (volba == 1) {
            int cisloKalkulacky;
            cout << "Vyber Kalkulacku (1, 2, 3):" << endl;
            cin >> cisloKalkulacky;

            if (cisloKalkulacky < 1 || cisloKalkulacky > 3) {
                cout << "Neplatne cislo kalkulacky!" << endl;
                continue;
            }

            int a, b;
            char operacia;
            cout << "Zadaj priklad (napr. 5 + 3): ";
            cin >> a >> operacia >> b;

            int vysledok = predajna.pouziKalkulacku(cisloKalkulacky, a, operacia, b);
            cout << "Vysledok: " << a << operacia << b << " = " << vysledok << endl;
        }
        else if (volba == 2) {
             int cisloKalkulacky;
            cout << "Vyber Kalkulacku (1, 2, 3):" << endl;
            cin >> cisloKalkulacky;

            int trzba= predajna.getTrzbaPokladne(cisloKalkulacky);
            cout << "Aktualna trzba pokladne " << cisloKalkulacky << " je: " << trzba << endl;
        }
        else if (volba == 3) {
            int celkovaTrzba = predajna.getCelkovaTrzba();
            cout << "CELKOVA TRZBA PREDAJNE: " << celkovaTrzba << endl;
        }
        else{
            cout << "Neplatna volba" << endl;
        }
    }

    return 0;
}
    
    
           
