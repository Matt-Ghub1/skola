#include <iostream>

class Animal
{
public:
    // treba virtual destruktor aby sme nemali memory leak / nedefinovane spravanie
    virtual ~Animal() {}
    // ak mame iba taketo metodu (pure virtual function)
    // tak sa jedna o abstraktnu triedu (sama o sebe nevie zit) vedia byt inicializovany iba jeho potomkovia
    virtual void makeSound() const = 0;
};

class Dog : public Animal
{
public:
    void makeSound() const override
    {
        std::cout << "woof\n";
    }
};

class Cat : public Animal
{
public:
    void makeSound() const override
    {
        std::cout << "meow\n";
    }
};

int main()
{
    // spolocne pole maciek a psov
    Animal *animals[2] = {new Dog, new Cat};
    for (std::size_t i = 0; i < 2; i++)
    {
        // nakolko obe dedia od Animal, vieme takto volat metody
        animals[i]->makeSound();
    }

    // alternativna inicializacia
    Cat *c = new Cat;
    Dog *d = new Dog;
    Animal *animalsAlt[2] = {c, d};
    for (std::size_t i = 0; i < 2; i++)
    {
        animalsAlt[i]->makeSound();
    }

    // nezabudnut vymazat vsetko co je dynamicky alokovane.
    delete c;
    delete d;
    // alternativa: namiesto delete c; delete d; vieme loopnut animalsAlt
    // for (std::size_t i = 0; i < 2; i++)
    //     delete animalsAlt[i];
    // (pouzijeme iba jedno z toho, inak by sme mazali dvakrat)
    // good practice je taktiez nastavit c = nullptr; d = nullptr; ak ich chcete dalej vyuzivat

    // pouzivame ak mame staticky incializovane pole teda pomocou [velkost]
    // avsak jeho prvky su incializovane dynamicky cez new vid. vyssie
    for (std::size_t i = 0; i < 2; i++)
    {
        delete animals[i];
    }

    // teraz mame pole dynamicky alokovane, teraz vieme pouzit delete[]
    Animal **animalsHeap = new Animal *[2];
    animalsHeap[0] = new Dog;
    animalsHeap[1] = new Cat;

    // vymazeme dynamicky alokovane prvky pola
    for (std::size_t i = 0; i < 2; i++)
        delete animalsHeap[i];

    // vymazeme dynamicky alokovane pole
    delete[] animalsHeap;
    return 0;
}