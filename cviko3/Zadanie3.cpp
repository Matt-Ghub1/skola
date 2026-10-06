#include <iostream>
#include <string>
using namespace std;

class Kalkulacka {
    public:
    int scitacia_pamat = 0;
    int vysledok = 0;
     int kalkulator(int cislo1, char oper, int cislo2) {
    if (oper == '+') {
        vysledok = cislo1 + cislo2;
    }
    else if (oper == '-') {
        vysledok = cislo1 - cislo2;
    }
    else if (oper == '*') {
        vysledok = cislo1 * cislo2;
    }
    else if (oper == '/') {
        vysledok = cislo1 / cislo2;
    }
    else if (oper == '^') {
        vysledok = 1;
        for (int i = 1; i <= cislo2; i++) {
            vysledok *= cislo1;
        }
    }
    scitacia_pamat += vysledok;
    return vysledok;
}
    
};

int main() {
    Kalkulacka kalkulacka1;
    Kalkulacka kalkulacka2;
    Kalkulacka kalkulacka3;
    int vyberkalk;
    
    while (true)
    {
        cout << "Vyber kalkulacku (1, 2, 3) alebo 0 pre ukoncenie: ";
        cin >> vyberkalk;

        if (vyberkalk == 0) 
            break;
    
        else if (vyberkalk < 1 || vyberkalk > 3)
        {
            cout << "Neplatny vyber. Skus znova." << endl;
            continue;
        }

        int a, b;
        char operacia;
        cout << "napis priklad s operaciami (-,+,*,/,^)" << endl;
        cin >> a >> operacia >> b;

        if (vyberkalk == 1) {
            cout << "Pouzivam kalkulacku 1" << endl;
            kalkulacka1.kalkulator(a,operacia,b);
            cout << "Vysledok: " << a << operacia << b << " = " << kalkulacka1.vysledok << endl;
        }
        else if (vyberkalk == 2) {
            cout << "Pouzivam kalkulacku 2" << endl;
            kalkulacka2.kalkulator(a,operacia,b);
            cout << "Vysledok: " << a << operacia << b << " = " << kalkulacka2.vysledok << endl;
        }
        else if (vyberkalk == 3) {
            cout << "pouzivam kalkulacku 3" << endl;
            kalkulacka3.kalkulator(a,operacia,b);
            cout << "Vysledok: " << a << operacia << b << " = " << kalkulacka3.vysledok << endl;
        }









    }

}
    
    
           
