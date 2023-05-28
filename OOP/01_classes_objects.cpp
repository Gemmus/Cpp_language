#include <iostream>

using namespace std;

class Employee{
public:				// private, public, protected; if not stated, standard: private
	string Name;
	string Company;
	int Age;
};

int main(){

	Employee employee1;
	employee1.Name = "Chloe";
	employee1.Company = "Bookworms Ltd.";
	employee1.Age = 36;

	return 0;
}
