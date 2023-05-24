#include <iostream>

using namespace std;

int main7(){

	string name;
	cout << "What is your name?  ";
	getline(cin, name);

	int age;
	cout << "What is your age?  ";
	cin >> age;

	cout << endl <<  "Hello " << name << "!" << endl;
	cout << "You are " << age << " years old." << endl;

	string full_name;
	cout << endl << "What is your full name?  ";
	getline(cin >> ws, full_name);			 // ws = white space
	cout << "Hello " << full_name << "!";


	return 0;
}
