/*
Continue to develop the class String from the exercise 3 further in the following way (use
the version from the phase 4, where dynamic array was used and destructor and copy
constructor were implemented in correct way).

Write the following operators to the class:
• assignment operator (=).
• output operator <<, that can be used to display the string to the screen.
• addition (plus) operator(+) , which makes a new string where the contents of the right
  side string has been concatenated to the contents of the left hand side string.
  Remember that it is not allowed to modify the operands of the +-operator.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

class String {

public:

    String(const char* string="") {
        c_string = new char[strlen(string) + 1];
        strcpy(c_string, string);
    }

    String(const String& s) {
        c_string = new char[strlen(s.c_string) + 1];
        strcpy(c_string, s.c_string);
    }

    ~String() {
        cout << c_string << " to be destroyed -->" ;
        delete c_string;
        cout << " done" << endl;
        //cout << "destructor done" << endl;
    }
/*
    const String& operator=(const String& right) const{

    }
*/
    friend ostream& operator<<(ostream& output, const String& s) {
        output << "" << s.c_string << "";
        return output;
    }

    String operator+(const String& s2) const{
        char* temp;
        temp = new char[strlen(c_string) + strlen(s2.c_string) + 1];

        strcpy(temp, c_string);
        strcat(temp, s2.c_string);

        return temp;
    }


private:

    char* c_string;

};

int main() {

    String s1("abcedf");
    String s2("ghijklmn");
    String sum;

    cout << "String 1 is: " << s1 << endl;
    cout << "String 2 is: " << s2 << endl;

    sum = s1 + s2;

    cout << "Sum is: " << sum << endl; // output should be: abcdefghijklmn

    // This should also work
    //sum = sum;
    //cout << "Sum is still: " << sum << endl;; // output should still be: abcdefghijklmn

    return 0;
}
