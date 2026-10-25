#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::queue<std::string> q;

    // --- pridavanie ---
    q.push("prvy"); // pridava sa vzdy na koniec
    q.push("druhy");
    q.push("treti");

    // --- pristup ---
    std::cout << q.front() << " " << q.back() << "\n"; // prvy (najstarsi) a posledny (najnovsi)
    std::cout << q.size() << " " << q.empty() << "\n"; // pocet prvkov, je prazdny?

    // --- vyberanie ---
    // pop() prvok len ZMAZE a nic nevracia, preto sa najprv precita front()
    while (!q.empty())
    {
        std::cout << q.front() << "\n"; // prvy, druhy, treti (poradie ako prisli)
        q.pop();
    }

    // PRECO JE SPECIALNY: FIFO, prvy dnu, prvy von. Ziadne [] a ziadne prechadzanie,
    //   vidis len zaciatok a koniec, co chranni pred pouzitim nespravnym sposobom.
    // KEDY: fronta uloh, tlac dokumentov, BFS (prehladavanie grafu), spracovanie sprav v poradi
    return 0;
}