/*
Part A) Conversion constructors and conversion operators
--------------------------------------------------------------------------------------------------------------
It is possible to use the constructor of the class String (our own String class from the previous exercises,
not the library class string) as a conversion constructor from c-style string to String object.

To convert a String object to a c-style string, type conversion operator is needed.
Write this kind of type conversion operator for the String class.

Test both conversions using the following test program.
void main() {
    String s;
    char name[30];
    s = "Matti"; //Conversion c-string -> String
    cout << s;
    strcpy(name, s); //Conversion String -> c-string
    cout << name;
}

Note that the String object is as a source parameter in the strcpy function. Write the type conversion
operator that allows a String object as a source parameter, but not as a destination parameter1 (for
the srtcpy function). If you allow String object to be used as the destination, it is not a good idea,
because it breaks the encapsulation and allows a programmer to go around the interface of String class.

Sometimes the automatic use of constructor for type conversion can be harmful. The programmer of the class
can avoid them by putting keyword explicit to precede the constructor in the class definition.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;
using namespace std;

class String {

public:

    String(const char* string = "") {
        c_string = new char[strlen(string) + 1];
        strcpy(c_string, string);
    }

    String(const String& s) {
        c_string = new char[strlen(s.c_string) + 1];
        strcpy(c_string, s.c_string);
    }

    ~String() {
        cout << "('" << c_string << "' to be destroyed -->";
        delete c_string;
        cout << " done)" << endl;
    }

    friend ostream& operator<<(ostream& output, const String& s) {
        output << "" << s.c_string << "";
        return output;
    }

    String operator+(const String& s2) const {
        char* temp;
        temp = new char[strlen(c_string) + strlen(s2.c_string) + 1];

        strcpy(temp, c_string);
        strcat(temp, s2.c_string);

        return temp;
    }

    String& operator=(const String& right) {
        if (this != &right) {
            delete c_string;
            c_string = new char[strlen(right.c_string) + 1];
            strcpy(c_string, right.c_string);
        }
        return *this;
    }

    String operator++(int) {
        String old(*this);
        char* temp = new char[strlen(c_string + 2)];
        strcpy(temp, c_string);
        delete c_string;
        strcat(temp, "X");
        c_string = temp;
        return old;
    }

    String& operator++() {
        char* temp = new char[strlen(c_string + 2)];
        strcpy(temp, c_string);
        delete c_string;
        strcat(temp, "X");
        c_string = temp;
        return *this;
    }

    char& operator[](int index) const {
        if (index >= 0 && index < strlen(c_string)) {
            return c_string[index];
        }
        else {
            return c_string[0];
        }
    }

    /**************************
     *         PART A         *
     **************************/

    operator const char*() const {
        return c_string;
    }

private:

    char* c_string;
};

int main() {
    String s;
    char name[30];

    s = "Matti"; //Conversion c-string -> String
    cout << "s: " << s << endl;

    strcpy(name, s); //Conversion String -> c-string
    cout << "name: " << name << endl;

    return 0;
}
