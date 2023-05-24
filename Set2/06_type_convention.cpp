//Type Conversion:
// - conversion a value of one data type to another
// - implicit = automatic
// - explicit = precede value with new data type (int) x

#include <iostream>

int main6(){

	double x = (int) 3.14;
	std::cout << x << std::endl;

	char y = 100;
	std::cout << (char) 100 << std::endl; //explicit

	int correct = 8;
	int questions = 10;
	double score = correct/(double)questions * 100;

	std::cout << score << "%";

	return 0;
}
