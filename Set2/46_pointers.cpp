// Pointers:
// variable that stores a memory address of another variable

#include <iostream>

using namespace std;

int main46(){

	string name = "Joseph";
	string *pName = &name;
	cout << pName << endl;  // prints memory address

	int age = 21;
	int *pAge = &age;
	cout << pAge << endl;   // prints memory address

	return 0;
}
