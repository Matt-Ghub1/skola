// C++ program to demonstrate array of strings using
// 2D character array
#include <iostream>

int main()
{
	// Initialize array of pointer
	const char *colour[4] = { "Blue", "Red",
						"Orange", "Yellow" };
	
	/*
	char *p = "Blue";   // points to a string literal → don't modify
	char a[] = "Blue";  // creates a modifiable array → can modify
	
	char *p = "Blue";
	p[0] = 'b'; // This is undefined behavior, as it modifies a string literal
	std::cout << p << "\n";
	
	char a[] = "Blue";
	a[0] = 'b'; // This is valid, as it modifies a character array
	std::cout << a << "\n";
	*/

	// Printing Strings stored in 2D array
	for (int i = 0; i < 4; i++)
		std::cout << colour[i] << "\n";
    // treti prvok z druheho stringu
    std::cout << colour[1][2] << "\n";
	return 0;
}
