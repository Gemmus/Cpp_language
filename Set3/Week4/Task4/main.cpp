/*
Well-designed class works in all situations in reliable way. We require that it must give correct results
even if somebody decides to pass the class object as a value parameter to the function. Return back to the version (phase 2)
where String object is passed a value parameter and fix the problem in another way. Therefore, write an appropriate copy
constructor for the class and observe that all three outputs are again correct. Why the copy constructor in the class fixes the problem?
*/

#include <iostream>
#include <string.h>

using namespace std;

class String {

public:

    String(const char* string) {
        c_string = new char[strlen(string) + 1];
        strcpy(c_string, string);
    }

    String(const String &s) {
        c_string = new char[strlen(s.c_string) + 1];
        strcpy(c_string, s.c_string);
    }

    ~String() {
        delete c_string;
        cout << "destructor done" << endl;
    }

    void list() {
        cout << c_string << endl;
    }

private:

    char *c_string;

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

/* _____________________________________________________________________________________________________________________________________________
     Output:
   ---------------------------------------------------------------------------------------------------------------------------------------------
     abcdefg
     abcdefg
     destructor done
     abcdefg
     destructor done
   _____________________________________________________________________________________________________________________________________________
     Explanation:
   ---------------------------------------------------------------------------------------------------------------------------------------------
     Copy constructor is making a copy of the original object dynamically and only the copy is destroyer at the end of the function call.
   _____________________________________________________________________________________________________________________________________________ */
