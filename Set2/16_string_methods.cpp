#include <iostream>

int main16(){

	std::string name;

	std::cout << "Enter your full name:  ";
	std::getline(std::cin, name);

	if(name.length() > 30){
		std::cout << "Your name can't be more than 30 characters." << std::endl;
	}
	else if(name.empty()){ // boolean
		std::cout << "You didn't enter your name." << std::endl;
	}
	else{
		std::cout << "Welcome " << name << "!" << std::endl;
	}

	int empty_space = name.find(' ');

	name.erase(empty_space, 1);  // index, n

	name.insert(empty_space, 1, '.');  // index, n, char

	name.append("@cpp.com");
	std::cout << "Your email is now: " << name;

	std::cout << name.at(2) << std::endl; // gets the character of the index

	name.clear(); // clears the variable

	return 0;
}
