#include <iostream>
#include <cmath>

int main8(){

	double x = 3;
	double y = 4;
	double z;

	//z = std::min(x, y); 	// --> 3
	//z = std::max(x, y); 	// --> 4
	//z = pow(2, 3); 		// --> 8
	//z = sqrt(9); 			// --> 3
	//z = abs(-3);			// --> 3
	//z = round(8.45);		// --> 8
	//z = round(8.75); 		// --> 9
	//z = ceil(3.23);  		// --> 4
	z = floor(3.87); 		// --> 3

	std::cout << z;

	return 0;
}
