#include <iostream>
using namespace std;

int main()
{
	long lcislo;
    auto sizeOflcislo = sizeof(lcislo);
    cout << "Size of long: " << sizeOflcislo << " bytes\n";
    long a[20];
    cout << "Size of array: " << sizeof(a) << " bytes\n";
	cout << "Number of elements: " << sizeof(a)/sizeof(a[0]) << "\n";
	return 0;
}
