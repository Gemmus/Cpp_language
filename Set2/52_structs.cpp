#include <iostream>

using namespace std;

struct student{
	string name;
	double gpa;
	bool enrolled = true;
};

int main52(){

	student student1;
	student1.name = "Harry";
	student1.gpa = 3.21;

	cout << student1.name << endl;
	cout << student1.gpa << endl;
	cout << student1.enrolled << endl;

	student student2;
	student2.name = "Lara";
	student2.gpa = 4.56;
	student2.enrolled = false;

	cout << student2.name << endl;
	cout << student2.gpa << endl;
	cout << student2.enrolled << endl;

	return 0;
}
