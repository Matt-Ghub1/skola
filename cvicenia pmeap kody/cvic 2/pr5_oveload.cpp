#include <iostream>
using namespace std;

// Pretazenie funkcie:
// Funkcie mozu mat rovnaky nazov, ale musia sa lisit parametrami
// (pocet parametrov alebo ich typ).
int power(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; ++i)
        result *= base;
    return result;
}

// Rovnaky nazov, ale iny pocet parametrov -> pretazena funkcia
int power(int base)
{
    return base*base;
}

int main()
{
    int a = 1;
    
    /*C++ vyberie funkciu podla poctu a typu argumentov, napr ak by ste 
    mali funkcie pre (flaot, int) a (int, int), kompilator vyberie tu spravnu.*/
    cout << "power(2, 3) = " << power(2, 3) << endl;
    cout << "power(2, 2) = " << power(2, 2) << endl;
    cout << "power(2) = " << power(2) << endl;


    system("pause");
    return 0;
}