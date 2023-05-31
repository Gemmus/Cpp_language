// Dynamic memory:
// Memory allocated after the program is already compiled and running.
// Use the 'new' operator to allocate memory in the heap rather than the stack.
// Useful when we don't know how much memory we will need.
// Makes our program more flexible, i.e. user input.

#include <iostream>

using namespace std;

int main49(){

	int *pNum = NULL;

	pNum = new int;

	*pNum = 21;

	cout << "address: " << pNum << endl;
	cout << "value: " << *pNum << endl;

	delete pNum; // to avoid memory leak

	////////////////////////////////////////

	char *pGrades = NULL;
	int size;

	cout << "How many arrays do you want?  ";
	cin >> size;

	pGrades = new char[size];

	for(int i = 0; i < size; i++){
		cout << endl << "Enter grade:  ";
		cin >> pGrades[i];
	}

	for(int i = 0; i < size; i++){
		cout << pGrades[i] << endl;
	}

	delete[] pGrades;

	return 0;
}
