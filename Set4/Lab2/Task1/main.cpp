/*
Write a program that asks user to enter a line that contains integers or “stop” to stop the program. If user enters a
string that starts with “stop” the program stops. Otherwise, the program creates a string stream from the user input and
reads integers from the stream. Program keeps reading and summing integer until the stream ends or reading an integer
fails because text or other nonnumerical character is encountered. When the reading stops the sum and count are printed and
program asks user to enter another string.
For example:
Enter a line with numbers or “stop”: 1 6 34 78 4 6
Total of 6 numbers is 129
Enter a line with numbers or “stop”: 4 99 zip 44 6
Total of 2 numbers is 103
Enter a line with numbers or “stop”: stop
*/

#include <iostream>
#include <sstream>

using namespace std;

int main(){

    bool no_stop = true;
    int sum, count, aux;
    string input;

    while (no_stop) {
        sum = 0;
        count = 0;

        cout << "Enter a line with numbers or \"stop\": ";
        getline(cin, input);
        if (input == "stop") {
            no_stop = false;
        } else {
            istringstream is(input);
            while (is >> aux) {
                sum += aux;
                count++;
            }
            cout << "Total of " << count << " is " << sum << endl;
        }
    }

    return 0;
}
