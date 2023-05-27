//Null value:
// - a special value that means something has no value
// - when a pointer is holding a null value, that pointer is not pointing at anything

// nullptr = keyword represents a null pointer literal, helps to determine if an address was successfully assigned to a pointer

// When using pointers, be careful that your code isn't dereferencing nullptr or pointing to free memory.

#include <iostream>

using namespace std;

int main47(){

	int *pointer = nullptr;
	int x = 123;

	pointer = &x;

	if(pointer  == nullptr){
		cout << "Address was not assigned!" << endl;
		cout << *pointer;
	}
	else{
		cout << "Address was assigned!" << endl;
	}

	return 0;
}
