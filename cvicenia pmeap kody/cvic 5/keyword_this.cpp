#include <iostream>

class Entity
{
private:
    int x, y;

public:
    // nezabudajte, ze ak vytvorime hocijaky konstruktor, tak sa default nevytvori
    Entity()
    {
        x = 0;
        y = 0;
    }

    Entity(int x, int y)
    {
        // ak mame vstupne premenne identicke k premennym triedy
        // tak vieme pouzit keyword "this" co je vlastne pointer na vlastnu triedu
        // teda v nasom pripade Entity *this, ak chceme modifikovat jeho premenne tak
        // ho treba dereferencovat co robime s -> a nasledne mame pristup na jeho atributy
        this->x = x;
        this->y = y;
        // vieme takto volat aj jeho funkcie
        this->printXY();
    }

    void printXY() const
    {
        std::cout << "x: " << x << " y: " << y << "\n";
    }
};

int main()
{
    Entity e;
    e.printXY();
    Entity e1(10, 20);
    return 0;
}