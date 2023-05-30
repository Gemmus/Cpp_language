#include <iostream>

using namespace std;

class Employee{
private:				// private, public, protected; if not stated, standard: private
	string Name;
	string Company;
	int Age;

public:
	Employee(string name, string company, int age){
		Name = name;
		Company = company;
		Age = age;
	}

	void setName(string name){
		Name = name;
	}

	string getName(){
		return Name;
	}

	void setCompany(string company){
		Company = company;
	}

	string getCompany(){
		return Company;
	}

	void setAge(int age){
		if(age >= 18){
			Age = age;
		}
	}

	int getAge(){
		return Age;
	}

	void Introduction(){
		cout << "Hi! I'm " << Name << ", I work for " << Company << " and I'm " << Age << " old." << endl;
	}
};

int main(){

	Employee employee1("Chloe", "Bookworms Ltd.", 36);
	Employee employee2("Mona", "Flower Delivered Ltd.", 23);
	employee1.Introduction();
	employee2.Introduction();

	employee1.setAge(37);
	cout << employee1.getName() << " is " << employee1.getAge() << " years old now." << endl;

	return 0;
}
