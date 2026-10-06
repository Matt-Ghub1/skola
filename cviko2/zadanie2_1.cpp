#include <iostream>
using namespace std;

int cislo1;
int cislo2;
char oper;
int vysledok = 0; 
int scitacia_pamat = 0; 

void kalkulator(int cislo1, int cislo2, char oper, int  &vysledok) {
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


}
int main() {
    cout << "Ahoj! napis cislo\n";
    cin >> cislo1;
    cout << "operator:\n";
    cin >> oper;
    cout << "druhe cislo: \n";
    cin >> cislo2;
    if (oper == '/' && cislo2 == 0) {
        cout << "Chyba: deleni nulou!" << endl;
        return 1;
    }
    
    {}
    kalkulator(cislo1, cislo2, oper, vysledok);
    cout << cislo1 << oper << cislo2 << " = " << vysledok << endl;
    cout << "scitacia pamat: " << scitacia_pamat << endl;

    if (oper == '/')  {
        cout << " zvysok: " << cislo1 % cislo2 << endl;
    }

    cout << "chces pokracovat? (Y/N)\n";
    char odpoved;
    cin >> odpoved;

    if (odpoved == 'Y') {
        main();
    }
    if (odpoved == 'N') {
        cout << "BYE BYE" << endl;
    }

    return 0;
}