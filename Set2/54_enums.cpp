#include <iostream>

using namespace std;

// If number is not assigned, first is automatically0, ... +1
enum Day{Mon = 1, Tue = 2, Wed = 3, Thu = 4, Fri = 5, Sat = 6, Sun = 7};

int main54(){

	enum Day today = Sun;

	if(today == Sat || today == Sun){
		cout << "It's weekend.";
	}
	else{
		cout << "It's weekday.";
	}

	return 0;
}
