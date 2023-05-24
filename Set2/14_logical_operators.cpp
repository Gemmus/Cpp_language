#include <iostream>

using namespace std;

int main14(){

	int temp;
	cout << "Enter a temperature:  ";
	cin >> temp;
	bool sunny = true;
	bool rainy = true;

	// && = AND
	if(temp > 0 && temp < 30){
		cout << "It's a good weather." << endl;
	}
	else{
		cout << "It's bad weather." << endl;
	}

	// || = OR
	if(20 < temp || sunny){
		cout << "It's a good weather." << endl;
	}
	else{
		cout << "It's bad weather." << endl;
	}

	// ! = NOT
	if(!rainy){
		cout << "It's not raining." << endl;
	}
	else{
		cout << "It's raining." << endl;
	}

	return 0;
}

