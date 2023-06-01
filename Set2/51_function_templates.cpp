// Function template:
// Describes what a function looks like.
// Can be used to generate as many overloaded functions as needed, each using different data types.

#include <iostream>

using namespace std;

template <typename A, typename B>

auto max51(A x, B y){
	return (x > y) ? x : y;
}

int main51(){

	cout << max51(1, 2.1) << endl;

	return 0;
}
