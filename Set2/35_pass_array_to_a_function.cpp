#include <iostream>

using namespace std;

double getTotal35(double prices[], int size){

	double total = 0;
	for(int i = 0; i < size; i++){
		total += prices[i];
	}

	return total;
}


int main35(){

	double prices[] = {8.00, 12.50, 9.30, 2.00, 55.99};
	int size = sizeof(prices)/sizeof(prices[0]);
	double total = getTotal35(prices, size);

	cout << "$" << total;

	return 0;
}
