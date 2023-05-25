#include <iostream>

using namespace std;

int main18(){

	int number;

	do{
		cout << "Enter a number:  ";
		cin >> number;
	}while(number < 0);

	cout << number;

	return 0;
}
