/*
Task 1
Write a Bohemic Number Game as follows:
Playing number game!
Give a number: 12
I won, mine is 13!
Give a number: 999
I won, mine is 1000!
Give a number:
(etc., the game continues infinitely)
*/

#include <iostream>

using namespace std;

int main() {

    int user_num = 0;

    cout << "Playing number game!" << endl;
    
    while (true) {
        cout << "Give a number: ";
        cin >> user_num;
        cout << "I won, mine is " << user_num + 1 << "!" << endl;
    }

    return 0;
}
