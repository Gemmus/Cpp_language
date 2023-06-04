// Abstraction: hiding unnecessary data from outside a class
// Getter: function that makes a private attribute READABLE
// Setter: function that makes a private attribute WRITEABLE

#include <iostream>

using namespace std;

class Stove{

private:

	int temperature = 0;

public:

	Stove(int temperature){
		setTemperature(temperature);
	}

	// GETTER //
	int getTemperature(){
		return temperature;
	}

	// SETTER //
	void setTemperature(int temperature){
		if(temperature < 0) {
			this->temperature = 0;
		}
		else if(temperature >= 10){
			this->temperature = 10;
		}
		else{
			this->temperature = temperature;
		}
	}
};

int main58(){

	Stove stove(3);

	stove.setTemperature(-3);

	cout << "Temperature setting is: " << stove.getTemperature();

	return 0;
}
