#include <iostream>
using namespace std;



int main() {
    char MenoPriezvisko[] = "Matus Grun";
    char pole[30][30];

    for (int i = 0; i < 30; i++)  {
        for (int j = 0; j < 30; j++){
            pole[i][j] = '*';
        }
    }

//tuto prepisujem meno a priezvisko do pola, tak aby sa pismena posuvali o jednu poziciu doprava a dole
    for (int i = 0; i < sizeof(MenoPriezvisko)/sizeof(MenoPriezvisko[0]); i++)  {
        for (int j = 0; j < 30; j++){
            char pametaj = MenoPriezvisko[i];
            pole[j][i+j] = MenoPriezvisko[i];
        }
    }


// tuto len vypisujem pole do terminalu
    for (int i = 0; i < 30; i++)  {
        for (int j = 0; j < 30; j++){
           cout << pole[i][j];
        }
        cout << "\n";
    }
    return 0;
}