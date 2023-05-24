#include <iostream>

using namespace std;

int main12(){

	char op;
	double num1;
	double num2;

	cout << "Enter the operation ( + - * / ):  ";
	cin >> op;

	if(op ==  '+'){
		cout << "Enter the first number:  ";
		cin >> num1;
		cout << "Enter the second number:  ";
		cin >> num2;
		cout << "The result is: " << num1 + num2;
	}
	else if(op == '-'){
		cout << "Enter the first number:  ";
		cin >> num1;
		cout << "Enter the second number:  ";
		cin >> num2;
		cout <<"The result is: " << num1 - num2;
	}
	else if(op == '*'){
		cout << "Enter the first number:  ";
		cin >> num1;
		cout << "Enter the second number:  ";
		cin >> num2;
		cout << "The result is: " << num1 * num2;
	}
	else if(op == '/'){
		cout << "Enter the first number:  ";
		cin >> num1;
		cout << "Enter the second number:  ";
		cin >> num2;
		cout << "The result is: " << num1 / num2;
	}
	else{
		cout << "Invalid input.";
	}

	return 0;
}
