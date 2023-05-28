#include <iostream>

using namespace std;

class Employee{
public:
	string Name;
	string Company;
	int Age;

	void Introduction(){
		cout << "Hi! I'm " << Name << ", I work for " << Company << " and I'm " << Age << " old." << endl;
	}
};

int main(){

	Employee employee1;
	employee1.Name = "Chloe";
	employee1.Company = "Bookworms Ltd.";
	employee1.Age = 36;
	employee1.Introduction();

	return 0;
}
