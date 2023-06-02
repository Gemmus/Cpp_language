#include <iostream>

using namespace std;

struct Cat {
	string name;
	int age;
	string colour;
};

void printCat53(Cat cat){
	cout << cat.name << endl << cat.age << endl << cat.colour << endl << endl;
}

void gotOlder53(Cat &cat){
	cat.age += 1;
}

int main53(){

	Cat cat1;
	cat1.name = "Nala";
	cat1.age = 4;
	cat1.colour = "white";
	printCat53(cat1);
	gotOlder53(cat1);
	printCat53(cat1);

	Cat cat2;
	cat2.name = "Tapio";
	cat2.age = 8;
	cat2.colour = "tabby";
	printCat53(cat2);
	gotOlder53(cat2);
	printCat53(cat2);

	return 0;
}

