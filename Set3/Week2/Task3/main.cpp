/*
How this Bohemic Number Game behaves, if the user gives the largest integer number the
computer is able to handle? (For the original description of the Bohemic Game, please refer to Task1 or Task2.)
Change the logic of the game so that in that case the game announces a tie. 
*/

#include <iostream>

#define MAX_INT 2147483647

using namespace std;

int main() {

    int user_num = 0;
    bool playing = true;

    cout << "Playing number game!" << endl;

    while (playing) {
        cout << "Give a number: ";
        cin >> user_num;
        if (MAX_INT == user_num) {
            cout << "It is a tie." << endl;
        } else if (0 == user_num){
            playing = false;
        } else {
            cout << "I won, mine is " << user_num + 1 << "!" << endl;
        }
    }

    cout << "You chose to quit by entering 0. Bye!" << endl;

    return 0;
}
