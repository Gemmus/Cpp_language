#include <iostream>

namespace first{
	int x = 1;
}

namespace second{
 	int x = 2;
}

using namespace std;
//but to avoid conflict: using std::cout; using std::string; etc.

int main3(){

	//int x = 0;

	//cout << x << endl;				// --> 0
	//cout << first::x << endl;		// --> 1
	//cout << second::x << endl;		// --> 2

	using namespace first;
	cout << x << endl;								// --> 1
	cout << second::x;								// --> 2

	return 0;
}
