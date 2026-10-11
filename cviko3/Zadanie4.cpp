#include <iostream>
#include <string>
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
    
};





/// TOTO ESTE UPRAV PRADAJNU NA TYPY
class Predajna {
    private:
        Kalkulacka Kalkulacka[3];


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

int main (){



}