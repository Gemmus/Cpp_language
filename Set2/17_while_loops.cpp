#include <iostream>

using namespace std;

int main17(){

	std::string name;

	while(name.empty()){
		cout << "Enter your name:  ";
		getline(std::cin, name);
	}

	cout << "Welcome " << name << "!" << std::endl;

	return 0;
}
