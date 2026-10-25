#include <iostream>
#include <string>
#include <vector>

// auto je NEZAVISLY typ a, b mozu byt int aj double
auto maxAuto(auto a, auto b) { return a > b ? a : b; }

// 1. parametre MUSIA mat rovnaky typ (T je pomenovany, auto by to nevedelo)
template <typename T>
T maxSame(T a, T b) { return a > b ? a : b; }

// 2. potrebujem T vnutri tela (T total{} vytvori nulu spravneho typu)
template <typename T>
T sumAll(const std::vector<T> &v)
{
    T total{};
    for (const auto &x : v) // tu je auto ideal, typ prvku ma nezaujima
        total += x;
    return total;
}

// 3. triedy: auto tu nefunguje, T sa musi pomenovat
template <typename T>
class Box
{
    T value;

public:
    Box(T v) : value(v) {}
    T get() const { return value; }
};

int main()
{
    auto n = 42; // auto pri premennej: kompilator vie, ze je to int
    std::vector<int> v{1, 2, 3};

    std::cout << maxAuto(3, 4.5) << "\n"; // OK: int a double, vyjde 4.5
    // std::cout << maxSame(3, 4.5);      // chyba: T nemoze byt int aj double naraz
    std::cout << maxSame(3, 4) << "\n"; // OK: obe int

    std::cout << sumAll(v) << "\n"; // 6, T = int
    Box<std::string> b("hello");
    std::cout << b.get() << " " << n << "\n";
    return 0;
}

// PRAVIDLO:
//   auto     -> premenne, for cykly, lambdy, jednoduche funkcie kde typ nie je dolezity
//   template -> ked parametre musia mat rovnaky typ, ked T pouzivam v tele,
//               pri triedach, alebo ked potrebujem non-type parameter (int N)