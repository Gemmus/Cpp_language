#include <iostream>
#include <ctime>

using namespace std;

int main23(){

	srand(time(0));
	int randNum = (rand() % 5) + 1;

	switch(randNum){
	case 1:
		cout << "You won a doll." << endl;
		break;
	case 2:
		cout << "You won a lollipop." << endl;
		break;
	case 3:
		cout << "You won a car toy." << endl;
		break;
	case 4:
		cout << "You won a sticker." << endl;
		break;
	case 5:
		cout << "You won a ball." << endl;
		break;
	}

	return 0;
}
