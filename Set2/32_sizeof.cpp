#include <iostream>

using namespace std;

int main32(){

	double gpa = 2.5;
	cout << sizeof(gpa) << " bytes" << endl;

	string name = "Bob";
	cout << sizeof(name) << " bytes" << endl;

	char grade = 'B';
	cout << sizeof(grade) << " bytes" << endl;

	char grades[] = {'A', 'B', 'C', 'D', 'F'};
	cout << sizeof(grades) << " bytes" << endl;
	cout << sizeof(grades)/sizeof(char) << " elements" << endl;

	string students[] = {"Noora", "Elena", "David", "Jean"};
	cout << sizeof(students)/sizeof(string) << " elements" << endl;

	return 0;
}
