#include <iostream>

using namespace std;

int main33(){

	string students[] = {"Noora", "Jack", "Elena", "David", "Jean"};

	for(int student = 0; student < sizeof(students)/sizeof(string); student++){
		cout << students[student] << endl;
	}

	char grades[] = {'A', 'B', 'C', 'D', 'F'};

	for(int i = 0; i < sizeof(grades)/sizeof(char); i++){
		cout << grades[i] << endl;
	}

	return 0;
}
