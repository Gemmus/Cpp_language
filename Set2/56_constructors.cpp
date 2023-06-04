// Constructor:
// Special method that is automatically called when an object is instantiated.
// Useful for assigning values to attributes as arguments.

#include <iostream>

using namespace std;

class Student{
	public:
		string name;
		int age;
		double gpa;

	Student(string name, int age, double x){ // x: if named differently, no this-> is needed
		this->name = name;
		this->age = age;
		gpa = x;
	}
};

int main56(){

	Student student1("Zoe", 16, 3.4);

	cout << student1.name << ", " << student1.age << " years old. GPA: " << student1.gpa << endl;

	return 0;
}
