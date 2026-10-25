#include <iostream>
#include <string>

// T je lubovolny typ, teda aky typ tam passneme takym bude aj T.
// Kompilator vygeneruje samostatnu verziu funkcie pre kazdy pouzity typ.
// Oba parametre musia byt rovnakeho typu (max(3, 4.5) by nefungovalo).
template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

// Typ sa urcuje pri vytvarani objektu: Box<int>, Box<std::string>...
// Kazde T vytvori uplne novu triedu.
template <typename T>
class Box
{
    T value;

public:
    Box(T v) : value(v) {}
    T get() const { return value; }
};

// K a V su dva nezavisle typy (key, value), mozu byt rozne aj rovnake
template <typename K, typename V>
struct Pair
{
    K key;
    V value;
};

// N nie je typ ale hodnota (cislo), musi byt znama pri kompilacii.
// Array<int, 5> a Array<int, 6> su dva rozne typy.
template <typename T, int N>
struct Array
{
    T data[N];
    int size() const { return N; }
};

// "..." je parameter pack, zoberie lubovolny pocet argumentov
// lubovolnych typov (aj kazdy iny typ).
//   typename... T -> pack typov
//   T... args     -> pack hodnot (parametrov funkcie)
//   args...       -> rozbalenie packu
template <typename... T>
void printAll(T... args)
{
    ((std::cout << args << " "), ...);
}

void simpleTypes()
{
    // T sa odvodi automaticky z argumentov (template argument deduction)
    std::cout << max(3, 4) << "\n";         // int max<int>(int a, int b)
    std::cout << max(3.12f, 3.54f) << "\n"; // float max<float>(float a, float b)
    std::cout << max('h', 'a') << "\n";     // char max<char>(char a, char b)

    // POZOR: T = const char *, porovnavaju sa adresy pointrov, nie text!
    std::cout << max("befds", "basd") << "\n"; // const char *max<const char *>(const char *a, const char *b)

    // T zadane explicitne v <>, argumenty sa skonvertuju na std::string,
    // takze sa uz porovnava skutocny text
    std::cout << max<std::string>("adam", "eva") << "\n"; // std::string max<std::string>(std::string a, std::string b)
}

void classTypes()
{
    // pri triedach sa T musi vzdy napisat explicitne (do C++17 bez CTAD)
    Box<int> a(42);              // trieda Box, kde T = int
    Box<std::string> b("hello"); // trieda Box, kde T = std::string

    std::cout << a.get() << " " << b.get() << "\n";
}

void multipleTypes()
{
    // K = std::string, V = int
    Pair<std::string, int> p{"age", 30};

    // T = int, N = 5 -> pole 5 intov, N sa urci pri kompilacii
    Array<int, 5> arr;

    std::cout << p.key << ": " << p.value << "\n";
    std::cout << "velkost: " << arr.size() << "\n"; // 5
}

void variadicTypes()
{
    // kazdy argument moze mat iny typ: int, double, const char *, char
    printAll(1, 2.5, "hello", 'x'); // 1 2.5 hello x
}

int main()
{
    simpleTypes();
    classTypes();
    multipleTypes();
    variadicTypes();
    return 0;
}