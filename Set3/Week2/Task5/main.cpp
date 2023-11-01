/*
Change the guessing game so that the user can specify the range between which the number
to be guessed is. Please refer for Task4 for guessing game description.
*/

#include <iostream>
#include <ctime>

using namespace std;

int main() {

    srand(time(0));

    int min_value = 0, max_value = 0;

    cout << "Enter the smallest value of the range: ";
    cin >> min_value;
    cout << "Enter the largest value of the range: ";
    cin >> max_value;

    int comp_num = (rand() % (max_value - min_value)) + min_value;
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
}
