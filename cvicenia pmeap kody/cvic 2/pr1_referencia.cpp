#include <iostream>
using namespace std;

/*Referencia je alias, teda druhé meno pre už existujúcu premennú. 
Dôležité pravidlá referencií:
- musia sa inicializovať hneď pri deklarácii (int &r; je chyba),
- po inicializácii sa nedajú presmerovať na inú premennú (referencia = b; nezmení, na čo referencia ukazuje, iba priradí hodnotu b do a),
- zmena cez referenciu zmení aj pôvodnú premennú a naopak.*/

int main()
{
    int a = 1;
    int b = 2;
    int &referencia = a;    //nevytvorí novú premennú ani kópiu, len povie, že referencia a a sú to isté miesto v pamäti. Preto oba výpisy ukážu 1.
    cout << "Hodnota premennej a: " << a << endl;
    cout << "Hodnota referencie: " << referencia << endl;
    cout << "Hodnota premennej b: " << b << endl << endl;

    referencia = 5;
    cout << "Hodnota premennej a: " << a << endl;
    cout << "Hodnota referencie: " << referencia << endl;
    cout << "Hodnota premennej b: " << b << endl << endl;
    
    referencia = b;         
    cout << "Hodnota premennej a: " << a << endl;
    cout << "Hodnota referencie: " << referencia << endl;
    cout << "Hodnota premennej b: " << b << endl;

    system("pause");
    return 0;
}