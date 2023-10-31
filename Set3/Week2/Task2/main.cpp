/*
Write a Bohemic Number Game as follows:
Playing number game!
Give a number: 12
I won, mine is 13!
Give a number: 999
I won, mine is 1000!
Give a number:
Modify the game so that the game will end when the user gives a zero.
*/

#include <iostream>

using namespace std;

int main() {

    int user_num = 0;
    bool playing = true;

    cout << "Playing number game!" << endl;

    while (playing) {
        cout << "Give a number: ";
        cin >> user_num;
        if (0 != user_num) {
            cout << "I won, mine is " << user_num + 1 << "!" << endl;
        } else {
            playing = false;
        }
    }
    
    cout << "You chose to quit by entering 0. Bye!" << endl;

    return 0;
}
