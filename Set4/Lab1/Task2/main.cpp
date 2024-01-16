/* Write a function that takes a reference to string and a character (by value) as parameters. The function replaces all
occurrences of the character with underscores. Write a program that ask user to enter a string. Then program asks user
to enter character to replace or “stop” to stop the program. Note that program must read a string after the second
question to be able to test for “stop”. If answer is not “stop” then program passes the first character of second
question’s answer as the character to replace. Then program prints the string and continues. If answer is “stop” the
program ends.
For example:
Enter a string: This is a test
Enter character to replace or “stop”: i
Result: Th_s _s a test
Enter a string: I love C++
Enter character to replace or “stop”: stop */

#include <iostream>

using namespace std;

void underscore(string &string1, char ch);

int main() {

    string text, word;
    while (word != "stop") {
        cout << "Enter a string: ";
        getline(cin, text);
        cout << "Enter character to replace or \"stop\": ";
        getline(cin, word);
        if (word != "stop")
            underscore(text, word[0]);
    }

    return 0;
}

void underscore(string &string1, char ch) {
    for (char & i : string1) {
        if (i == ch) {
            i = '_';
        }
    }
    cout << "Result: " << string1 << endl;
}
