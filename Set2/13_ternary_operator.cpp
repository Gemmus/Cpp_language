#include <iostream>

int main13(){

	int grade = 75;
	grade >= 60 ? std::cout << "You pass." << std::endl : std::cout << "You fail." << std::endl;

	int number = 9;
	number % 2 ? std::cout << "odd" << std::endl : std::cout << "even" << std::endl;

	bool hungry = true;
	//hungry ? std::cout << "Let's eat now!" << std::endl: std::cout << "Let's eat later!" << std::endl;
	// or
	std::cout << (hungry ? "Let's eat now!" : "Let's eat later!");

	return 0;
}
