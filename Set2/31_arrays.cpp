#include <iostream>

using namespace std;

int main31(){

	string cars[] = {"Corvette", "Mustang", "Volvo"};

	cout << cars[0] << endl;

	cars[0] = "Camaro";
	cout << cars[0] << endl;

	string cats[2];

	cats[0] = "Mirri";
	cats[1] = "Mustard";

	cout << cats[0] << endl;
	cout << cats[1] << endl;

	double prices[] = {8.00, 12.50, 9.30, 2.00};

	cout << prices[0] << endl;
	cout << prices[1] << endl;

	return 0;
}
