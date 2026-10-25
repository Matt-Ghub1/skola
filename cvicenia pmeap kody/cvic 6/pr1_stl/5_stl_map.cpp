#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, int> ages;

    // --- pridavanie ---
    ages["adam"] = 30;        // [] vytvori zaznam ak neexistuje, inak prepise hodnotu
    ages.insert({"eva", 25}); // insert existujuci zaznam NEPREPISE
    ages.emplace("jan", 40);  // vytvori zaznam priamo v mape

    // --- pristup ---
    std::cout << ages.at("adam") << "\n";   // at() hodi vynimku ak kluc neexistuje
    std::cout << ages.count("eva") << "\n"; // 1 ak kluc existuje, inak 0
    std::cout << ages.size() << "\n";       // pocet dvojic
    ages["nikto"];                          // POZOR: [] aj pri citani vytvori zaznam s hodnotou 0

    // --- mazanie ---
    ages.erase("jan"); // zmaze podla kluca

    // --- prechadzanie (range-for, viac v iterators.cpp) ---
    for (const auto &p : ages)
        std::cout << p.first << "=" << p.second << "\n"; // zoradene podla kluca: adam, eva, nikto

    // PRECO JE SPECIALNY: dvojice kluc -> hodnota, kluce unikatne a vzdy zoradene,
    //   hladanie O(log n). Ak poradie nepotrebujes, unordered_map je rychlejsi (priemerne O(1)).
    // KEDY: slovnik, pocitanie vyskytov (mapa[slovo]++), vyhladavanie podla mena/id
    return 0;
}