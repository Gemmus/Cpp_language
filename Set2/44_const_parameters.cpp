#include <iostream>

using namespace std;

void printInfo44(const string &name, const int &age){ 	// to make parameters read only
	cout << name << endl << age << endl;
}

int main44(){

	string name = "Lana";
	int age = 21;

	printInfo44(name, age);

	return 0;
}
