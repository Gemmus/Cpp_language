#include <iostream>

using namespace std;

int main9(){

	double sales = 95000;
	double state_tax_procentage = 0.04;
	double county_tax_procentage = 0.02;

	double state_tax = sales * state_tax_procentage;
	double county_tax = sales * county_tax_procentage;

	cout << "Sales: $" << sales << endl
		 << "State tax: $" << state_tax << endl
		 << "County tax: $" << county_tax << endl;

	return 0;
}
