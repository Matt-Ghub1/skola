#include <iostream>
#include <cstring>
#include <string>
using namespace std;


int main() {
class ovocie {
    public:
    int vaha;
    int cena;
    char druh[20];
};

ovocie jablko;

jablko.vaha = 100;
jablko.cena = 50;
strcpy(jablko.druh, "jablko");

cout << "vaha: " << jablko.vaha << endl;
cout << "Cena: " << jablko.cena << endl;
cout << "Druh: " << jablko.druh << endl;

return 0;
}