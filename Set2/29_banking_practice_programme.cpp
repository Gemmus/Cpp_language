#include <iostream>
#include <iomanip>

using namespace std;

void showBalance29(double balance){
										// setting it for 2 decimals
	cout << endl << "Your balance is $" << setprecision(2) << fixed << balance << "." << endl;
}

double deposit29(){

	double amount;

	cout << "Enter the sum you want to deposit:  ";
	cin >> amount;

	while(amount < 0){
		cout << endl << "Invalid input." << endl
			 << "Enter the sum you want to deposit:  ";
		cin >> amount;
	}

	return amount;

}

double withdraw29(double balance){

	double amount;

	cout << "Enter the sum you want to withdraw:  ";
	cin >> amount;

	while(amount < 0){
		cout << endl << "Invalid input" << endl
					 << "Enter the sum you want to withdraw:  ";
				cin >> amount;
	}

	while((balance - amount) < 0){
		cout << endl << "Insufficient amount" << endl
			 << "Enter the sum you want to withdraw:  ";
		cin >> amount;
	}

	return amount;
}

int main29(){

	double balance = 0;
	int choice = 0;
	do{
		cout << endl << "1. Show Balance" << endl
				 << "2. Deposit Money" << endl
				 << "3. Withdraw Money" << endl
				 << "4. Exit" << endl
				 << endl << "Enter you choice:  ";
			cin >> choice;

			switch(choice){
			case 1: showBalance29(balance);
					break;
			case 2: balance += deposit29();
					showBalance29(balance);
					break;
			case 3: balance -= withdraw29(balance);
					showBalance29(balance);
					break;
			case 4: cout << "Thanks for visiting!" << endl;
					break;
			default: cout << "Invalid input." << endl;
					 break;
			}

	}while(choice != 4);

	return 0;
}
