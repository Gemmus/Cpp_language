#include <iostream>

using namespace std;

int main41(){

	string questions[] = {"1. What year was C++ created?:  ",
						  "2. Who invented C++?:  ",
						  "3. What is the predecessor of C++?:  "};

	string options[][4] = {{"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
						   {"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zuckerberg"},
						   {"A. C", "B. C+", "C. C--", "D. B++"}};

	char answers[3] = {'C', 'B', 'A'};

	unsigned int size = sizeof(questions)/sizeof(questions[0]);
	char guess;
	int score = 0;

	for(unsigned int i = 0; i < size; i++){
		cout << questions[i] << endl;
		for(unsigned int j = 0; j < sizeof(options[i])/sizeof(options[i][0]); j++){
			cout << options[i][j] << endl;
		}

		cin >> guess;
		guess = toupper(guess);

		if(guess == answers[i]){
			score++;
			cout << "Correct!";
		}
		else{
			cout << "Wrong." << endl << "The correct answer is: " << answers[i] << "." << endl;
		}
	}

	cout << "Result: " << score << "/3" << endl;

	return 0;
}
