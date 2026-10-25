#include <iostream>
using namespace std;

// Parent class
class P1 {
public:
    virtual void show() {  // virtual for polymorphism
        cout << "This is class P1 (Parent)" << endl;
    }
};

// Child class 1
class C1 : public P1 {
public:
    void show() override {
        cout << "This is class C1 (Child 1)" << endl;
    }
};

// Child class 2
class C2 : public P1 {
public:
    void show() override {
        cout << "This is class C2 (Child 2)" << endl;
    }
};

int main() {
    // Universal variable (pointer to parent)
    P1* obj;

    // Point to Parent object
    P1 p;
    obj = &p;
    obj->show();   // Calls P1 version

    // Point to Child 1 object
    C1 c1;
    obj = &c1;
    obj->show();   // Calls C1 version

    // Point to Child 2 object
    C2 c2;
    obj = &c2;
    obj->show();   // Calls C2 version

    return 0;
}