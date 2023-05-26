#include <iostream>

using namespace std;

int main40(){

	string cars[][3] = {{"Volvo", "Audi", "BMW"},   // row size is optional
						{"Mustang", "Hummer", "Skoda"},
						{"Mazda", "Lexus", "Suzuki"}};

	int rows = sizeof(cars)/sizeof(cars[0]);
	int columns = sizeof(cars[0])/sizeof(cars[0][0]);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			cout << cars[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
