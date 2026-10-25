#include <iostream>
using namespace std;
  
class car {
public:
    int car_id;
    double distance;
  
    void distance_travelled();
  
    void display(int a, int b)
    {
        cout << "car id is=\t" << a << "\ndistance travelled =\t" << b + 5;
    }
};
  
int main()
{
    car c1; // Declare c1 of type car
    c1.car_id = 321;
    c1.distance = 12;
    c1.display(321, 12);
  
    return 0;
}