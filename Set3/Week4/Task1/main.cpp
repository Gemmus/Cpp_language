/*
Write the class string that has only one data member c_string. This data member represents
a string which is similar in C-language.

In this phase 1 we assume that the maximum number of characters of the string is 10. That's
why we can declare the string (the character array) inside the class definition as follows
char c_string[11];

In this phase 1 you should do the following member functions for the class String1:
• constructor that takes the string to be stored in String object as a parameter.
• list, that displays the string on the screen

In addition to these two member functions, write the third function (ordinary function, not
a member of the class) f that takes String object as a parameter and only displays the
contents of the string to the screen using String class member function list. The prototype of
the function is:
void f(String s);

Test the class String using the following test program:
void main() {
    String s("abcdefg");
    s.list();
    f(s);
    s.list();
}

Examine the outputs from the program and note that all of them are correct.
*/

#include <iostream>
#include <cstring>

using namespace std;

class String{

public:

    String(const char* string) {
        uint32_t length = strlen(string);
        if (length > 10) {
            length = 10;
        }
        strncpy(c_string, string, length);
        c_string[length] = '\0';
    }

    void list() {
        for (int i = 0; c_string[i] != '\0'; i++) {
            cout << c_string[i];
        }
        cout << endl;
    }

private:
    
    char c_string[11];
    
};

void f(String s);

int main() {

    String s("abcdefg");
    s.list();
    f(s);
    s.list();

    return 0;
}

void f(String s) {
    s.list();
}
