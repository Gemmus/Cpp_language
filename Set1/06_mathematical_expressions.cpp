#include <iostream>

int main6(){

	int x = 10;
	int y = 3;
	int z = x + y;
	std::cout << z << "\n";

	int m = x % y;
	std::cout << m << "\n";

	double a = 10;
	double b = a / y;
	std::cout << b << "\n";

	int c = 10;
	// int d = c++; // c = 11, d = 10
	//std::cout << c;
	//std::cout << d;

	int e = ++c; // c = 11, z = 11
	std::cout << c << "\n";
	std::cout << e << "\n";

	return 0;
}
