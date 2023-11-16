/*
Modify the class definition so that dynamic character array is used to store characters of the string. 
To avoid memory leaks in this case, add the destructor function to the class. 
To better understand how the program works make your destructor to display a message, for example, “destructor done”. 
Then you can easily follow when and how many times destructor is executed.
 
Don’t modify the main function. Run the program with the new version of the class String.
You are going to see, that this program will crash, or it displays wrong results. 
Try to find the correct explanation why it does not work. There are two ways to fix this problem (see phase 3 and phase 4).
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
     �o�a
     free(): double free detected in tcache 2
   _____________________________________________________________________________________________________________________________________________ 
     Explanation:
   ---------------------------------------------------------------------------------------------------------------------------------------------    
     Because the function is creating a copy of the parameter "String s", which appears as a new, second object to the first, original one.
   _____________________________________________________________________________________________________________________________________________ */
