// Recursion:
// Programming technique where a function invokes itself from within.
// A complex concept is broken into repeatable single steps.

// (iterative vs recursive)

// Advantages:
// - less and cleaner code
// - useful for sorting and searching algorithms
// Disadvantages:
// - uses more memory
// - slower

#include <iostream>

using namespace std;

void iterativeWalk50(int steps){
	for(int i = 0; i < steps; i++){
		cout << "Walk" << endl;
	}
	cout << endl;
}

void recursiveWalk50(int steps){
	if (steps > 0){
		cout << "Walk" << endl;
		recursiveWalk50(steps - 1);
	}
	cout << endl;
}

int iterativeFactFunc50(int number){
	int result = 1;
	for(int i = 1; i <= number; i++){
		result *= i;
	}
	return result;
}

int recursiveFactFunc50(int number){
	if(number > 1){
		return number * recursiveFactFunc50(number - 1);
	}
	else{
		return 1;
	}
}

int main50(){

	iterativeWalk50(2);
	recursiveWalk50(2);

	/////////////////////////////////////
	// Factorial function for both ways:

	int it_result = iterativeFactFunc50(6);
	int re_result = recursiveFactFunc50(6);
	cout << "Iterative result: " << it_result << endl;
	cout << "Recursive result: " << re_result << endl;

	return 0;
}
