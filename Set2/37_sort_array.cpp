#include <iostream>

using namespace std;

void sort37(int array[], int size){
	int temp;
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < size - i - 1; j++){ // for descending order: >
			if(array[j] > array[j + 1]){
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main37(){

	int numbers[] = {10, 6, 3, 4, 2, 8, 7, 1, 9, 5};
	int size = sizeof(numbers)/sizeof(numbers[0]);

	sort37(numbers, size);

	for(int element : numbers){
		cout << element << " ";
	}

	return 0;
}


