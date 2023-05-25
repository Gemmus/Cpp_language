#include <iostream>

using namespace std;

void happyBirthday25(int times, string name){
	for(int i = 0; i < times; i++){
		cout << "Happy B-day to " << name << "!" << endl;
	}
}

int main25(){

	string name = "Lisa";

	happyBirthday25(5, name);

	return 0;
}
