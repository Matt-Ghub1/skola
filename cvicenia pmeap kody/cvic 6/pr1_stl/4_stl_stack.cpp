#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::stack<char> st;

    // --- pridavanie ---
    for (char c : std::string("abc"))
        st.push(c); // pridava sa navrch

    // --- pristup ---
    std::cout << st.top() << "\n";                       // 'c', vidno len vrchny prvok
    std::cout << st.size() << " " << st.empty() << "\n"; // pocet prvkov, je prazdny?

    // --- vyberanie ---
    // pop() prvok len ZMAZE a nic nevracia, preto sa najprv precita top()
    while (!st.empty())
    {
        std::cout << st.top(); // cba, opacne poradie ako sme vkladali
        st.pop();
    }
    std::cout << "\n";

    // PRECO JE SPECIALNY: LIFO, posledny dnu, prvy von. Pristup len na vrch.
    // KEDY: undo/redo, kontrola zatvoriek v kode, DFS, vyhodnocovanie vyrazov,
    //   vsade kde sa treba vracat v opacnom poradi
    return 0;
}