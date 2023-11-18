/*
Fix the problem using reference parameter in the function f instead of value parameter.
Why this very small modification fixes the problem?
*/

#include <iostream>
#include <string.h>

using namespace std;

class String{

public:

    String(const char* string) {
        c_string = new char[strlen(string) + 1];
        strcpy(c_string, string);
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

void f(String &s);

int main() {

    String s("abcdefg");
    s.list();
    f(s);
    s.list();

    return 0;
}

void f(String &s) {
    s.list();
}

/* _____________________________________________________________________________________________________________________________________________ 
     Output: 
   ---------------------------------------------------------------------------------------------------------------------------------------------  
     abcdefg
     abcdefg
     abcdefg
     destructor done
   _____________________________________________________________________________________________________________________________________________ 
     Explanation:
   ---------------------------------------------------------------------------------------------------------------------------------------------    
     Because now it is referring to the memory address which is not destroyed after the function call.
   _____________________________________________________________________________________________________________________________________________ */
