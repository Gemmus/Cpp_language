#include <iostream>

using namespace std;

int main10(){

	int age;
	cout << "Enter your age:  ";
	cin >> age;

	if(age >= 18){
		cout << "Welcome!";
	}
	else if(age < 0){
		cout << "Invalid age.";
	}
	else{
		cout << "Entrance denied.";
	}

	return 0;
}
