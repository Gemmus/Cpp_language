#include <iostream>

int main3(){

	int counter = 36; // declaring variable "without setting a value"
	int members = 100;
	int temp = 0;

	temp = counter;
	counter = members;
	members = temp;

	std::cout << counter << "\n";

	std::cout << members << "\n";

	return 0;
}
