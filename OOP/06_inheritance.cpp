#include <iostream>

using namespace std;

class AbstractEmployee{
	virtual void AskForPromotion()=0;
};

class Employee: AbstractEmployee{
private:
	string Company;
	int Age;

protected:
	string Name;

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

class Developer: public Employee{
public:
	string FavProgLang;

	Developer(string name, string company, int age, string favProgLang)
	:Employee(name, company, age){
		FavProgLang = favProgLang;
	}

	void FixBug(){
		cout << getName() << " is debugging using " << FavProgLang << "." << endl;
	}

};

class Teacher: public Employee{
public:
	string Subject;

	Teacher(string name, string company, int age, string subject)
	:Employee(name, company, age){
		Subject = subject;
	}

	void PrepareLesson(){
		cout << Name << " is preparing for " << Subject << " lesson." << endl;
	}
};

int main(){

	Developer developer1("Jonathan", "ElectCode", 28, "C++");
	developer1.Introduction();
	developer1.FixBug();
	developer1.AskForPromotion();

	Teacher teacher1("Jack", "Sunnyside-up School", 59, "math");
	teacher1.Introduction();
	teacher1.PrepareLesson();
	teacher1.AskForPromotion();

	return 0;
}
