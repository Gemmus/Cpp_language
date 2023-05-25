#include <iostream>

using namespace std;

void bakingPizza27(){
	cout << "Pizza is ready!" << endl;
}

void bakingPizza27(string topping1){
	cout << "Pizza with " << topping1 << " is ready!" << endl;
}

void bakingPizza27(string topping1, string topping2){
	cout << "Pizza with " << topping1 << " and " << topping2 << " is ready!" << endl;
}


int main27(){

	bakingPizza27();
	bakingPizza27("mushroom");
	bakingPizza27("prosciutto cotto", "parmesan");

	return 0;
}
