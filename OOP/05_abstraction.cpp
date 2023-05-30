/*

#include <iostream>

using namespace std;

class AbstractEmployee{
	virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee{
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

	void AskForPromotion(){
		if(Age>30){
			cout << Name << " got promoted." << endl;
		}
		else{
			cout << Name << " is not promoted." << endl;
		}
	}
};

int main(){

	Employee employee1("Chloe", "Bookworms Ltd.", 36);
	Employee employee2("Mona", "Flower Delivered Ltd.", 23);
	employee1.AskForPromotion();
	employee2.AskForPromotion();

	return 0;
}
*/
