#include <iostream>

using namespace std;

int main11(){
	cout << "Enter the degree in Fahrenheit:  ";
	double fahrenheit;
	cin >> fahrenheit;

	double celsius = (fahrenheit - 32) * 5 / 9;
	cout << endl << "The temperature in Celsius is: " << celsius << " degree.";

	return 0;
}
