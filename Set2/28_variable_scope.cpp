#include <iostream>

using namespace std;

int number1 = 4;
int number2 = 5;

void printNumber28(){
	int number1 = 2;
	cout << number1 << endl;
	cout << ::number1 << endl; // :: --> print global version
	cout << number2 << endl;
}

int main28(){

	int number1 = 1;
	cout << number1 << endl;
	cout << ::number1 << endl; // :: --> print global version
	cout << number2 << endl;

	printNumber28();

	return 0;
}
