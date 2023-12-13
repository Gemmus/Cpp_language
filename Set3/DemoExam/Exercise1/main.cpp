/*
Let’s assume that class String (that is used to store strings) is defined in the following way:

class String {
public:
 //public member functions
 //
private:
 char *str;
};

This means that strings are internally stored as C-like strings (as character arrays in dynamic
memory). The advantage of using class here is that it is much easier for the user to use strings if
suitable member functions and operator overloading are done. Now we want that class String can be
used in the following way in the application:

int main() {
 String s1("abcde "), s2, s3;
 s2 = s1; //string obj s2 contains the same string "abcde" than s1
 s3 = s1 + s2; //a new string is constructed that contains s1 and
 //s2 concatenated. s1 and s2 must not be modified!
 cout << s2 << s3; //the output is "abcde" and "abcdeabcde"
 return 0;
}

Write the complete definition for class String and implement all member functions,
operators or other things needed to make the application program (main) above
possible. One additional requirement is that the program must not cause any memory leaks. (6p)
*/
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

class String {
    friend ostream& operator<<(ostream &out, const String &s_out) {
        out << s_out.str << " ";
        return out;
    }
public:
    String(const char *s="") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    String(const String &s) {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    ~String() {
        delete str;
    }

    String operator+(const String &right) const {
        char *aux;
        aux = new char[strlen(str) + strlen(right.str) + 1];
        strcpy(aux, str);
        strcat(aux, right.str);
        return aux;
    }

    String& operator=(const String &s0) {
        if (this != &s0) {
            delete str;
            str = new char[strlen(s0.str) + 1];
            strcpy(str, s0.str);
        }
        return *this;
    }

private:
    char *str;
};

int main() {
    String s1("abcde"), s2, s3;
    s2 = s1; //string obj s2 contains the same string "abcde" than s1
    s3 = s1 + s2; //a new string is constructed that contains s1 and
    //s2 concatenated. s1 and s2 must not be modified!
    cout << s2 << s3; //the output is "abcde" and "abcdeabcde"
    return 0;

}



