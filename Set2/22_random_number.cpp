#include <iostream>
#include <ctime>

using namespace std;

int main(){

	srand(time(0));

	int num1 = (rand() % 6) + 1;
	cout << num1 << endl;

	int num2 = (rand() % 6) + 1;
	cout << num2 << endl;

	int num3 = (rand() % 6) + 1;
	cout << num3 << endl;

	return 0;
}
