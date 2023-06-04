#include <iostream>

using namespace std;

class Animal{
public:
	bool alive = true;

	void eat(){
		cout << "This animal is eating." << endl;
	}
	void drink(){
		cout << "This animal is drinking." << endl;
	}
	void sleep(){
		cout << "This animal is sleeping." << endl;
	}
};

class Dog: public Animal{
public:
	void bark(int times){
		for (int i = 0; i < times; i++){
			cout << "Woof!" << endl;
		}
	}
};

class Cat: public Animal{
public:
	void meow(int times){
		for (int i = 0; i < times; i++){
			cout << "Meow!" << endl;
		}
	}
};


int main591(){

	Dog dog;
	cout << dog.alive << endl;
	dog.eat();
	dog.bark(3);

	Cat cat;
	cout << cat.alive << endl;
	cat.sleep();
	cat.meow(2);

	return 0;
}
