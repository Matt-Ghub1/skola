#include <iostream>
using namespace std;

int main()
{
    // obycajny pointer (int *). Mozem menit hodnotu cez pointer AJ presmerovat pointer inde.
    cout << endl << "klasicky pointer: int *" << endl;
    int v = 10;
    int w = 20;
    int *p = &v;
    cout << "p ukazuje na v, *p = " << *p << endl;
    *p = 11;                       // OK: menim hodnotu cez pointer
    cout << "Po *p = 11 -> v = " << v << endl;
    p = &w;                        // OK: pointer teraz ukazuje na w
    cout << "Po p = &w -> *p = " << *p << " (adresa: " << p << ")" << endl;


    //pointer na "konstantu" (const int *). Cez pointer NEMOZEM menit hodnotu, ale premennu v menit mozem.
    cout << endl << "pointer na konstantu" << endl;
    v = 10;
    const int *const_v_pointer = &v;
    v = 2;
    cout << "Hodnota premennej v: " << v << endl;
    cout << "Hodnota pozicie premennej \"v\" v pamati: " << const_v_pointer << endl;
    v = 3;
    cout << "Hodnota premennej v: " << v << endl;
    cout << "Hodnota pozicie premennej \"v\" v pamati: " << const_v_pointer << endl;
    cout << "Hodnota na ktoru ukazuje pointer (*const_v_pointer): " << *const_v_pointer << endl;


    // konstantny pointer (int * const). Hodnotu menit mozem, ale pointer sa uz nikdy nepresmeruje.
    cout << endl << "konstantny pointer: int * const" << endl;
    v = 10;
    int *const const_pointer = &v; // MUSI byt inicializovany hned
    cout << "*const_pointer = " << *const_pointer << endl;
    *const_pointer = 42;           // OK: menim hodnotu cez pointer
    cout << "Po *const_pointer = 42 -> v = " << v << endl;
    // const_pointer = &w;         // CHYBA: assignment of read-only variable


    // konstantny pointer na konstantu (const int * const). Neda sa menit ani hodnota cez pointer, ani pointer samotny.
    cout << endl << "konstantny pointer na konstantu: const int * const" << endl;
    const int *const const_const_pointer = &v;
    cout << "*const_const_pointer = " << *const_const_pointer << endl;
    // *const_const_pointer = 1;   // CHYBA: hodnotu cez pointer menit nemozem
    // const_const_pointer = &w;   // CHYBA: pointer presmerovat nemozem

    system("pause");
    return 0;
}