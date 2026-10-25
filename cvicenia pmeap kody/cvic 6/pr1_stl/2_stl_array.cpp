#include <array>
#include <iostream>

int main()
{
    // array: pole fixnej velkosti, velkost je sucast typu (std::array<int, 5>)
    std::array<int, 5> a{1, 2, 3, 4, 5};

    // --- pristup ---
    std::cout << a[0] << " " << a.at(1) << "\n";       // [] bez kontroly, at() hodi vynimku ak je mimo
    std::cout << a.front() << " " << a.back() << "\n"; // prvy a posledny prvok
    std::cout << a.size() << "\n";                     // 5, vzdy konstanta

    // --- uzitocne ---
    std::array<int, 5> b = a;      // kopia celeho pola hodnotou (C pole to nevie)
    a.fill(0);                     // nastavi vsetky prvky na 0
    std::cout << (a == b) << "\n"; // porovnanie celeho pola naraz, tu 0
    // a.data() vrati obycajny pointer, ked treba volat C funkciu

    // CO NEMA: push_back, resize, insert... velkost sa nikdy nemeni
    // PRECO JE SPECIALNY: ziadna alokacia na heape, rovnako rychly ako C pole,
    //   ale s rozhranim kontajnera (size, at, ==, kopirovanie)
    // KEDY: velkost je znama pri kompilacii (RGB farba, 3x3 matica, dni v tyzdni)
    return 0;
}