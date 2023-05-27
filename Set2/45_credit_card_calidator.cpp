// Luhn algorithm:
// 1. Double every second digit from right to left, if doubled number is 2 digits, split them.
// 2. Add all single digits from step 1.
// 3. Add all odd number digits from right to left.
// 4. Sum results from step 2 and 3.
// 5. If step 4 is divisible by 10, it is valid.

// Example:
//  	6011 0009 9013 9424
// 1.   6 1  0 0  9 1  9 2
// 1.   12 2 0 0 18 2 18 4
// 1.   1 2 2 0 0 1 8 2 1 8 4
// 2.   29
// 3.    0 1  0 9  0 3  4 4
// 3.   21
// 4.   29 + 21 = 50
// 5.   50 % 10 = 0 --> valid

#include <iostream>

using namespace std;

int getDigit45(const int number){

	return number % 10 + (number / 10 % 10);
}

int sumOddDigits45(const string cardNumber){

	int sum = 0;
	for(int i = cardNumber.size() - 1; i >= 0; i -=2){
		sum += cardNumber[i] - '0';
	}

	return sum;
}

int sumEvenDigits45(const string cardNumber){

	int sum = 0;
	for(int i = cardNumber.size() - 2; i >= 0; i -=2){
		sum += getDigit45((cardNumber[i] - '0') * 2);
	}

	return sum;
}

int main45(){

	string cardNumber;
	int result = 0;

	cout << "Enter a credit card number:  ";
	cin >> cardNumber;

	result = sumEvenDigits45(cardNumber) + sumOddDigits45(cardNumber);

	if(result % 10 == 0){
		cout << "Valid card number." << endl;
	}
	else{
		cout << "Invalid card number." << endl;
	}

	return 0;
}
