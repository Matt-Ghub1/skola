#include <iostream>
#include <set>

int main()
{
    std::set<int> s{5, 1, 3, 3}; // duplikat 3 sa ignoruje, s = {1, 3, 5}

    // --- pridavanie ---
    s.insert(2);                     // s = {1, 2, 3, 5}
    bool added = s.insert(3).second; // false, 3 tam uz je (second hovori, ci sa pridalo)
    std::cout << added << "\n";

    // --- hladanie ---
    std::cout << s.count(2) << "\n"; // 1 ak je v sete, inak 0
    std::cout << s.size() << "\n";   // pocet prvkov

    // --- mazanie ---
    s.erase(1); // zmaze podla hodnoty, s = {2, 3, 5}

    // --- prechadzanie (range-for, viac v iterators.cpp) ---
    for (int x : s)
        std::cout << x << " "; // 2 3 5, vzdy zoradene
    std::cout << "\n";

    // PRECO JE SPECIALNY: kazda hodnota najviac raz a vzdy zoradene,
    //   hladanie, vkladanie aj mazanie O(log n). Prvok sa po vlozeni neda menit.
    //   Ak poradie nepotrebujes, unordered_set je rychlejsi.
    // KEDY: odstranenie duplikatov, rychla kontrola "uz som to videl?", zoradeny unikatny zoznam
    return 0;
}