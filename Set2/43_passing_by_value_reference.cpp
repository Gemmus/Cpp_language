#include <iostream>

using namespace std;

void swapValue43(string x, string y){   // passed by value, doesn't swap

	string temp;

	temp = x;
	x = y;
	y = temp;
}

void swapReference43(string &x, string &y){   // passed by reference, swaps

	string temp;

	temp = x;
	x = y;
	y = temp;
}

int main43(){

	string x = "water";
	string y = "lemonade";

	swapValue43(x, y);

	cout << x << endl;
	cout << y << endl << endl;

	swapReference43(x, y);

	cout << x << endl;
	cout << y << endl << endl;

	return 0;
}
