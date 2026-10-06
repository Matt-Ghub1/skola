#include <iostream>
using namespace std;


int main() {

int vyska;
int sirka;
int stred_v;
int stred_s;
int r;
int x;
int y;

cout << "Zadaj vysku: ";
cin >> vyska;
cout << "Zadaj sirku: ";
cin >> sirka;
cout << "Zadaj polomer: ";
cin >> r;
stred_v = vyska-1; 
stred_s = sirka-1;

for (int i = 0; i < vyska; i++) {
    for (int j = 0; j < sirka; j++) {
        x = j*2;  //nasobim lebo nechcem delit neparne cisla :D
        y = i*2;
        if ((x - stred_s) * (x - stred_s) + (y - stred_v) * (y - stred_v) <= r * r*4) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
    }
    cout << endl;
}
}