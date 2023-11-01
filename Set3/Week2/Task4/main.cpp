/*
Create a guessing game where the computer first guesses an integer between 1 and 100. The
user then tries to guess the number, and after each guess the computer tells the user whether
the guess was too small or too large. After a correct guess, the computer prints the number
of guesses used:
Guess a number (1 – 100): 50
Too small!
Guess a number (1 – 100): 90
Too large!
Guess a number (1 – 100): 85
Too large!
Guess a number (1 – 100): 63
Right! You made 4 guesses.
Find by yourself show to generate random numbers in C++ (there are several alternatives).
*/

#include <iostream>
#include <ctime>

using namespace std;

int main() {

    srand(time(0));

    int min_value = 1;
    int max_value = 100;

    int comp_num = (rand() % max_value) + min_value;
    int user_num = 0;
    int counter = 0;
    bool guessed = false;

    // cout << "Comp_num = " << comp_num << endl;
    while (!guessed) {

        cout << "Guess a number (" << min_value << " - " << max_value << "): ";
        cin >> user_num;

        if (user_num > comp_num) {
            cout << "Too large!" << endl;
        } else if (user_num < comp_num) {
            cout << "Too small!" << endl;
        } else if ( user_num == comp_num) {
            guessed = true;
        }

        counter++;
    }

    cout << "Right! You made " << counter << " guesses." << endl;

    return 0;
