#include <iostream>

using namespace std;

int main38(){

	const int SIZE  = 10;

	string foods[SIZE];

	fill(foods, foods + (SIZE/2), "pizza");  // beginning point, end point, content
	fill(foods + (SIZE/2), foods + SIZE, "sushi");

	for(string food : foods){
		cout << food << endl;
	}

	return 0;
}

