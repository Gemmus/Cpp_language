/*                             B) Unary operators

                  B1) (Post increment and pre-increment operators)
Write pre-increment and post-increment operators for the class String. Both of the operators
append only one X-character at the end of the string object (so that it is easy to see in the
output).

                  B2) (Indexing operator)
Write an indexing operator for the class String that can be used to access individual
characters of the String object.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
/*
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif
*/

/////////////////////////// JARKKO ///////////////////////////
#define TASKB2 // Define selected task (TASKA, TASKB1, TASKB2)
//////////////////////////////////////////////////////////////

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
        cout << "('" << c_string << "' to be destroyed -->" ;
        delete c_string;
        cout << " done)" << endl;
        //cout << "destructor done" << endl;
    }

    /**************************
     *         TASK  A        *
     **************************/
    friend ostream& operator<<(ostream& output, const String& s) {
        output << "" << s.c_string << "";
        return output;
    }

    const String operator+(const String& s2) const {
        char* temp;
        temp = new char[strlen(c_string) + strlen(s2.c_string) + 1];

        strcpy(temp, c_string);
        strcat(temp, s2.c_string);

        return temp;
    }

    const String& operator=(const String& right) {
        if (this != &right) {
            delete c_string;
            c_string = new char[strlen(right.c_string) + 1];
            strcpy(c_string, right.c_string);
        }
        return *this;
    }

    /**************************
     *        TASK  B1        *
     **************************/
    String operator++(int) {
        String old(*this);
        strcat(c_string, "X");
        return old;
    }

    String& operator++() {
        strcat(c_string, "X");
        return *this;
    }

    /**************************
     *        TASK  B2        *
     **************************/
    char& operator[](int index) const {
        if (index >= 0 && index < strlen(c_string)) {
            return c_string[index];
        } else {
            return c_string[0];
        }
    }

private:

    char* c_string;

};

int main() {

    /**************************
     *         TASK  A        *
     **************************/
#ifdef TASKA
    String s1("abcedf");
    String s2("ghijklmn");
    String sum;

    cout << "String 1 is: " << s1 << endl;
    cout << "String 2 is: " << s2 << endl;

    sum = s1 + s2;

    cout << "Sum is: " << sum << endl; // output should be: abcdefghijklmn

    // This should also work
    sum = sum;
    cout << "Sum is still: " << sum << endl; // output should still be: abcdefghijklmn
#endif

    /**************************
     *        TASK  B1        *
     **************************/
#ifdef TASKB1
    String s_b1("abcdefg");
    cout << "Printing s++: " << s_b1++ << endl;
    cout << "After s++, the value of S: " << s_b1 << endl;
    cout << "Now printing ++s: " << ++s_b1 << endl;
#endif

    /**************************
     *        TASK  B2        *
     **************************/
#ifdef TASKB2
    String s_b2("abcdefg");
    for (int i = 0; i < 7; i++)
        cout << s_b2[i] << " ";
    cout << endl;
    s_b2[4] = 'X';
    for (int i = 0; i < 7; i++)
        cout << s_b2[i] << " ";
    cout << endl;
#endif

    return 0;
}
