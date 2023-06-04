// Overloaded Constructors:
// Multiple constructors with same name, but different parameters
// Allows for varying arguments when instantiating an object

#include <iostream>

using namespace std;

class Pizza{
	public:
		string topping1;
		string topping2;

		Pizza(){

		}
		Pizza(string topping1){
			this->topping1 = topping1;
		}

		Pizza(string topping1, string topping2){
			this->topping1 = topping1;
			this->topping2 = topping2;
		}
};

int main57(){

	Pizza pizza1("mushroom");
	Pizza pizza2("pepperoni", "bacon");
	Pizza pizza3;

	return 0;
}
