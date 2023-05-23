#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main18(){

	srand(time(0));
	const short minValue = 1;
	const short maxValue = 6;

	short first_number = (rand() % (maxValue - minValue + 1) + minValue); // 1 - 6
	short second_number = (rand() % (maxValue - minValue + 1) + minValue); // 1 - 6
	cout << first_number << endl << second_number;

	return 0;
}
