#include <iostream>

using namespace std;

int searchArray36( int numbers[], int size, int my_number){

	for(int i = 0; i < size; i++)
		if(numbers[i] == my_number){
			return i;
		}

	return -1;  // if none found
}


int main36(){

	int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = sizeof(numbers)/sizeof(numbers[0]);

	int index;
	int my_number;

	cout << "Enter a number to search for:  ";
	cin >> my_number;

	index = searchArray36(numbers, size, my_number);

	if(index != -1){
		cout << my_number << " is at index " << index << ".";
	}
	else{
		cout << my_number << " is not found.";
	}

	return 0;
}
