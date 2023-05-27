#include <iostream>


using namespace std;

int main42(){

	string name = "Lana";
	int age = 21;
	bool student = true;

	cout << &name << endl;		 // hexadecimal
	cout << &age << endl;		 // hexadecimal --> converted to decimal --> takes 4 byte
	cout << &student << endl;	 // hexadecimal --> converted to decimal --> takes 1 byte

	return 0;
}
