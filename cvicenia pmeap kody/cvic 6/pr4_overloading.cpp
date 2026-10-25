#include <iostream>

struct Vec2
{
    int x, y;

    // operator+ vrati NOVY objekt, ziadny operand sa nemeni (preto const)
    Vec2 operator+(const Vec2 &o) const
    {
        return {x + o.x, y + o.y};
    }

    // operator+= meni this, preto vracia referenciu na seba (a += b += c)
    Vec2 &operator+=(const Vec2 &o)
    {
        x += o.x;
        y += o.y;
        return *this;
    }

    // operator== vracia bool, nic nemeni, preto const
    bool operator==(const Vec2 &o) const
    {
        return x == o.x && y == o.y;
    }

    // unarny minus, bez parametra: -a
    Vec2 operator-() const
    {
        return {-x, -y};
    }

    // Vec2 * cislo: lavy operand je Vec2, takze moze byt clen triedy
    Vec2 operator*(int k) const
    {
        return {x * k, y * k};
    }
};

// cislo * Vec2: lavy operand je int, clen triedy int nemoze byt,
// preto musi ist o volnu funkciu
Vec2 operator*(int k, const Vec2 &v)
{
    return v * k;
}

// operator<<: lavy operand je std::ostream, takze tiez volna funkcia.
// friend netreba, lebo x a y su public (pri private by bol friend)
std::ostream &operator<<(std::ostream &os, const Vec2 &v)
{
    return os << "(" << v.x << ", " << v.y << ")"; // vracia os, aby islo cout << a << b
}

int main()
{
    Vec2 a{1, 2}, b{3, 4};

    std::cout << a + b << "\n";    // (4, 6)
    std::cout << -a << "\n";       // (-1, -2)
    std::cout << a * 3 << "\n";    // (3, 6)
    std::cout << 3 * a << "\n";    // (3, 6), vyuzije volnu funkciu
    std::cout << (a == b) << "\n"; // 0

    a += b;                             // a je teraz (4, 6)
    std::cout << a << " " << b << "\n"; // b sa nezmenilo
    return 0;
}