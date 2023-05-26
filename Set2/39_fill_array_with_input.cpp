#include <iostream>

using namespace std;

int main39(){

	string foods[5];
	int size = sizeof(foods)/sizeof(foods[0]);
	string temp;

	for(int i = 0; i < size; i++){
		cout <<  "Enter a food you like or 'q' to quit:  ";
		getline(cin, temp);
		if(temp != "q"){
			foods[i] = temp;
		}
		else{
			break;
		}
	}

	cout << endl << "You like the following foods:" << endl;

	for(int i = 0; !foods[i].empty(); i++){
		cout << foods[i] << endl;
	}

	return 0;
}
