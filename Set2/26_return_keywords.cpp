#include <iostream>
#include <cmath>

using namespace std;

double areaCalculator26(double number){
	return pow(number, 2);
}

double volumeCalculator26(double number){
	return pow(number, 3);
}

int main26(){

	double number;

	cout << "Enter side of the square:  ";
	cin >> number;

	double area = areaCalculator26(number);
	cout << "The area of the square is: " << area << " squaremetres." << endl;

	double volume = volumeCalculator26(number);
	cout << "The volume of the square is: " << volume << " cubic metres." << endl;

	return 0;
}
