#include <iostream>

struct Num
{
    int v;

    // PRIRADUJE (robi to, co ma robit =)
    Num &operator+(const Num &o)
    {
        v = o.v;
        return *this;
    }

    // SCITAVA (robi to, co ma robit +)
    Num &operator=(const Num &o)
    {
        v += o.v;
        return *this;
    }
};

int main()
{
    // v jazyku C++ vas nikto nekontroluje, aku neplechu robite
    // Priorita operatorov ostava zachovana (+ pred =), preto a + a = b
    Num a{10}, b{3}, c{10}, d{10};

    a + a = b;                // = ma nizsiu prioritu ako +, cize (a + a) = b
                              // (a + a): a sa priradi samo sebe a vrati sa a
                              // (...) = b: k a sa pripocita b -> a = 13, vyzera to ako (a + b)
    std::cout << a.v << "\n"; // 13

    c = b;                    // vyzera ako priradenie, ale scitava
    std::cout << c.v << "\n"; // 13

    d + b;                    // vyzera ako sucet, ale priradi
    std::cout << d.v << "\n"; // 3
    return 0;
}
