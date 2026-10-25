#include <iostream>
using namespace std;

// Odovzdanie referenciou: volanie je swap_ref(x, y), v tele pracujem s a, b priamo
void swap_ref(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Odovzdanie pointrom: volanie je swap_ptr(&x, &y), v tele musim dereferencovat
void swap_ptr(int *a, int *b)
{
    if (a == nullptr || b == nullptr) // pointer moze byt nullptr, treba kontrolovat
        return;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 1;
    int b = 2;

    /*
    - Referencia: pouziva sa ako obycajna premenna.
    - Pointer: hodnotu ziskame dereferenciou (*p).
    */
    cout << "Deklaracia" << endl;
    int &ref = a;
    int *ptr = &a;
    cout << "ref = " << ref << endl;
    cout << "*ptr = " << *ptr << endl;
    ref = 10;                      // zmenim a cez referenciu
    cout << "Po ref = 10 -> a = " << a << endl;
    *ptr = 20;                     // zmenim a cez pointer
    cout << "Po *ptr = 20 -> a = " << a << endl;

    /*
    &ref je adresa PUVODNEJ premennej (referencia nema vlastnu adresu).
    &ptr je adresa samotneho pointra, ptr je adresa premennej a.*/
    cout << endl << "Adresy" << endl;
    cout << "&a   = " << &a << endl;
    cout << "&ref = " << &ref << "  (rovnaka ako &a)" << endl;
    cout << "ptr  = " << ptr << "  (rovnaka ako &a)" << endl;
    cout << "&ptr = " << &ptr << "  (adresa samotneho pointra)" << endl;

    /*Presmerovanie
        ref = b NEPRESMERUJE referenciu, len skopiruje hodnotu b do a.
        ptr = &b presmeruje pointer na b.*/
    cout << endl << "=== 3) Presmerovanie ===" << endl;
    a = 1;
    b = 2;
    ref = b;                       // do a sa priradi hodnota b
    cout << "Po ref = b -> a = " << a << ", b = " << b
         << ", &ref == &a: " << (&ref == &a) << endl;

    a = 1;
    ptr = &b;                      // ptr ukazuje teraz na b
    cout << "Po ptr = &b -> *ptr = " << *ptr
         << ", a = " << a << ", ptr == &b: " << (ptr == &b) << endl;


    /*Referencia MUSI byt inicializovana a vzdy ukazuje na platny objekt.
    Pointer moze byt neinicializovany aj nullptr ("ukazuje nikam").*/
    cout << endl << "=== 4) Inicializacia a nullptr ===" << endl;
    // int &zla_ref;               // CHYBA: referencia musi byt inicializovana
    // int &nulova_ref = nullptr;  // CHYBA: referencia nemoze byt null
    int *prazdny = nullptr;        // OK
    if (prazdny == nullptr)
        cout << "prazdny je nullptr, nesmiem ho dereferencovat" << endl;
    // cout << *prazdny;           // NEDEFINOVANE SPRAVANIE (pad programu)


    //ten isty swap dvoma sposobmi
    cout << endl << "=== 5) Funkcie ===" << endl;
    int x = 1, y = 2;
    cout << "Pred: x = " << x << ", y = " << y << endl;
    swap_ref(x, y);                // referencie: volanie vyzera ako pri hodnotach
    cout << "Po swap_ref(x, y):   x = " << x << ", y = " << y << endl;

    swap_ptr(&x, &y);              // pointre: adresy musim odovzdat explicitne
    cout << "Po swap_ptr(&x, &y): x = " << x << ", y = " << y << endl;

    swap_ptr(nullptr, &y);         // pointer mozem odovzdat aj prazdny, referenciu nie
    cout << "Po swap_ptr(nullptr, &y): x = " << x << ", y = " << y << " (nic sa nestalo)" << endl;

    system("pause");
    return 0;
}