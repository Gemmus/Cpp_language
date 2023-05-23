#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main17(){

	srand(time(0));
	int number = rand() % 10; // 0 - 9
	cout << number;

	return 0;
}
