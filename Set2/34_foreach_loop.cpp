#include <iostream>

using namespace std;

int main34(){

	string students[] = {"Noora", "Jack", "Elena", "David", "Jean"};

	for(string student : students){
		cout << student << endl;
	}

	int grades[] = {1, 2, 3, 4, 5};
	for(int grade: grades){
		cout << grade << endl;
	}

	return 0;
}
