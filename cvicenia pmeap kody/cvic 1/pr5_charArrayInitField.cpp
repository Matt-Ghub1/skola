// C++ program to demonstrate array of strings using
// 2D character array
#include <iostream>

int main()
{
	// Initialize 2D array
	char colour[4][10] = { "Blue", "Red", "Orange",
						"Yellow" };

	// Printing Strings stored in 2D array
	for (int i = 0; i < 4; i++)
		std::cout << colour[i] << "\n";

	// Third element of second string
    std::cout << "\n" << colour[1][2] << "\n \n";

	colour[1][2] = 'X';
	// Printing Strings stored in 2D array
	for (int i = 0; i < 4; i++)
		std::cout << colour[i] << "\n";

	system("pause");
	return 0;
}
