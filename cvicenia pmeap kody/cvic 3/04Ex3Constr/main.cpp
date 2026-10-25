// C++ program to demonstrate constructors
 
#include <iostream>
using namespace std;
class A
{
    public:
    int id;
     
    //Default Constructor
    A()
    {
        cout << "Default Constructor called" << endl;
        id=-1;
    }
     
    //Parameterized Constructor
    A(int x)
    {
        cout << "Parameterized Constructor called" << endl;
        id=x;
    }
};
int main() {
     
    // obj1 will call Default Constructor
    A obj1;
    cout << "A id is: " <<obj1.id << endl;
     
    // obj1 will call Parameterized Constructor
    A obj2(21);
    cout << "A id is: " <<obj2.id << endl;
    return 0;
}