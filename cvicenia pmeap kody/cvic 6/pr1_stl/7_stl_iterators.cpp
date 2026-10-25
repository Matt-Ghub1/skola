#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

int main()
{
    std::vector<int> v{3, 1, 2};
    std::set<int> s{3, 1, 2};
    std::map<std::string, int> m{{"adam", 30}, {"eva", 25}};

    // --- teoria ---
    // Iterator je objekt, ktory sa sprava ako pointer na prvok kontajnera:
    //   *it          -> hodnota prvku
    //   ++it         -> posun na dalsi prvok
    //   it != end()  -> este nie sme na konci
    // Rozsah je [begin, end): begin() je prvy prvok, end() je ZA poslednym (nedereferencovat!)
    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " "; // 3 1 2
    std::cout << "\n";

    // --- preco je lepsi nez for (int i = 0; i < n; i++) v[i] ---
    //   1. funguje na VSETKYCH kontajneroch: set a map nemaju [], indexovy cyklus tam nejde
    //   2. rovnaky kod pre kazdy kontajner, zmenis typ a cyklus ostane
    //   3. ziadne chyby s indexom (o jedno mimo, porovnanie int so size_t)
    //   4. algoritmy (sort, find...) beru iteratory
    for (auto it = s.begin(); it != s.end(); ++it) // a pre set (zoradene)
        std::cout << *it << " ";
    std::cout << "\n";
    for (auto it = m.begin(); it != m.end(); ++it) // map: *it je pair, it->first a it->second
        std::cout << it->first << "=" << it->second << " ";
    std::cout << "\n";

    // --- varianty ---
    for (auto it = v.rbegin(); it != v.rend(); ++it) // rbegin() posledny, rend() PRED prvym, ide odzadu
        std::cout << *it << " ";                     // 2 1 3
    std::cout << "\n";
    // cbegin()/cend() su const iteratory, prvky sa cez ne nedaju menit

    for (const auto &x : v)    // range-for pouziva begin()/end() pod kapotou, najcitatelnejsie
        std::cout << x << " "; // ked staci prejst vsetko
    std::cout << "\n";

    // --- algoritmy a upravy ---
    std::sort(v.begin(), v.end()); // v = {1, 2, 3}
    v.insert(v.begin() + 1, 9);    // vlozi pred poziciu: {1, 9, 2, 3}
    v.erase(v.begin());            // zmaze prvok na pozicii: {9, 2, 3}

    // --- kategorie ---
    //   random access (vector, array, deque): it + 2, it[2]
    //   bidirectional (set, map): ++ a --, ale NIE it + 2, pouzi std::next
    //   stack a queue iteratory nemaju
    // POZOR: po insert/erase alebo realokacii mozu byt stare iteratory neplatne
    return 0;
}