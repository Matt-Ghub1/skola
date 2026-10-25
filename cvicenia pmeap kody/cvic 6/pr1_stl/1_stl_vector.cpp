#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{3, 1, 2};

    // --- pridavanie ---
    v.push_back(5);    // prida na koniec: {3, 1, 2, 5}
    v.emplace_back(4); // vytvori prvok priamo vo vektore: {3, 1, 2, 5, 4}

    // --- pristup ---
    std::cout << v[0] << " " << v.at(1) << "\n";       // [] bez kontroly, at() hodi vynimku ak je mimo
    std::cout << v.front() << " " << v.back() << "\n"; // prvy a posledny prvok

    // --- velkost ---
    std::cout << v.size() << " " << v.empty() << "\n"; // pocet prvkov, je prazdny?
    v.reserve(100);                                    // vyhradi pamat dopredu (size sa nemeni, capacity ano)
    std::cout << v.capacity() << "\n";                 // kolko sa zmesti bez realokacie

    // --- prechadzanie (range-for, viac v iterators.cpp) ---
    for (const auto &x : v)
        std::cout << x << " "; // 3 1 2 5 4, v poradi vkladania
    std::cout << "\n";

    // --- mazanie ---
    v.pop_back(); // zmaze posledny
    v.resize(2);  // zmensi/zvacsi na 2 prvky
    v.clear();    // zmaze vsetko, size = 0 (capacity ostane)
    // insert, erase, sort a pod. pouzivaju iteratory, pozri iterators.cpp

    // PRECO JE SPECIALNY: prvky su v jednom suvislom bloku pamate, takze [] je O(1)
    //   a prechadzanie je velmi rychle. Pridavanie na koniec je rychle, na zaciatok
    //   alebo do stredu pomale (prvky sa posuvaju). Velkost sa meni za behu.
    // KEDY: predvoleny vyber, ked nevies, co pouzit. Zoznam prvkov, ktory rastie,
    //   a cita sa podla indexu alebo od zaciatku do konca.
    return 0;
}