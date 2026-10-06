// C++ program to print elements of Three-Dimensional
// Array
#include<iostream>
using namespace std;

int main()
{
	// initializing the 3-dimensional array
	int x[][3][2] =
	{
		{ {0,1}, {2,3}, {4,5} },
		{ {6,7}, {8,9}, {10,11} }
	};

	// output each element's value
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				cout << "Element at x[" << i << "][" << j
					<< "][" << k << "] = " << x[i][j][k]
					<< endl;
			}
		}
	}
	cout << "\n";

	int size_i = sizeof(x) / sizeof(x[0]);
	int size_j = sizeof(x[0]) / sizeof(x[0][0]);
	int size_k = sizeof(x[0][0]) / sizeof(x[0][0][0]);

	for (int i = 0; i < size_i; ++i)
	{
		for (int j = 0; j < size_j; ++j)
		{
			for (int k = 0; k < size_k; ++k)
			{
				cout << "Element at x[" << i << "][" << j << "][" << k
					<< "] = " << x[i][j][k] << endl;
			}
		}
	}


	system("pause");
	return 0;
}
