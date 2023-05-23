#include <iostream>
#include <cmath>

using namespace std;

int main13(){

	cout << "Enter the radius of the circle in metre:  ";
	double radius;
	cin >> radius;
	const double pi = 3.14;
	double area = pi * pow(radius, 2);
	cout << endl << "The area of the circle is: " << area << " squaremetres.";

	return 0;
}
