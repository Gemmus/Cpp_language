#include <iostream>
#include <cmath>

using namespace std;

int main9(){

	double a;
	double b;
	double c;

	cout << "Enter side A:  ";
	cin >> a;

	cout << "Enter side B:  ";
	cin >> b;

	c = sqrt(pow(a, 2) + pow(b, 2));

	cout << endl << "Side C is: " << c;

	return 0;
}
