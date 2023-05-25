#include <iostream>
#include <ctime>

using namespace std;

int main24(){

	srand(time(0));

	int number = rand() % 51;
	int guess;

	cout << "Enter a number between 0 and 50:  ";
	cin >> guess;

	do{
		if(number < guess){
			cout << "Too high!" << endl
				 << "Enter a number between 0 and 50:  ";
			cin >> guess;
		}
		else if(number > guess){
			cout << "Too low!" << endl
				 << "Enter a number between 0 and 50:  ";
			cin >> guess;
		}
	}while(number != guess);

	cout << "You guessed it. It was " << number << ".";

	return 0;
}
