#include <iostream>

using namespace std;

class Human{
	public:
		string name;
		string occupation;
		int age;

		void eat(){
			cout << name << " is eating." << endl;
		}
		void drink(){
			cout << name << " is drinking." << endl;
		}
		void sleep(){
			cout << name << " is sleeping." << endl;
		}
};

int main55(){

	Human human1;
	human1.name = "Patrick";
	human1.occupation = "scientist";
	human1.age = 35;

	human1.eat();

	Human human2;
	human2.name = "Morty";
	human2.occupation = "student";
	human2.age = 15;

	human2.sleep();

	return 0;
}
