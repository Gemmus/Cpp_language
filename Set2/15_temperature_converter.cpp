#include <iostream>

using namespace std;

int main15(){

	char unit;
	double temp;

	cout << "To what would you like to convert to?" << endl
		 << "Fahrenheit(F) or Celsius(C):  ";
	cin >> unit;

	if(unit == 'c' || unit == 'C'){
		cout << "Enter temperature in Fahrenheit:  ";
		cin >> temp;
		cout << "The result is " << (temp - 32) * 1.8 << " Celcius.";
	}
	else if(unit == 'f' || unit == 'F'){
		cout << "Enter temperature in Celsius:  ";
		cin >> temp;
		cout << "The result is " << (1.8 * temp) + 32 << " Fahrenheit.";
	}
	else{
		cout << "Invalid input.";
	}


	return 0;
}
