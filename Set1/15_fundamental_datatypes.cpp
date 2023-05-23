#include <iostream>

using namespace std;

int main15(){

	double price = 99.99;
	float interestRate = 3.67f; // f or F needs to be added, otherwise complier will treat is as a double which might potentially cause data lost
	long fileSize = 90000L; // l (can be misread as 1) or L, it allows auto to recognize
	char letter = 'a'; // single quotation mark
	bool isValid = false;
	auto letter2 = 'b'; // can recognize data types automatically

	int number {}; // another method to initialize an empty variable

	return 0;
}
