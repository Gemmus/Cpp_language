#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

////////////////////// JARKKO /////////////////////
#define TASK1 // Define selected task (TASK1-TASK5)
///////////////////////////////////////////////////

using namespace std;

                                               ////////////////////////////////////////////
                                               //                TASK 1                  //
                                               ////////////////////////////////////////////
#ifdef TASK1

class String{

public:

    String(const char* string) {
        strcpy(c_string, string);
    }

    void list() {
        cout << c_string << endl;
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

/* ____________________________________________________________________________________________________________________________________________
     Output:
   --------------------------------------------------------------------------------------------------------------------------------------------
     abcdefg
     abcdefg
     abcdefg
   ____________________________________________________________________________________________________________________________________________ */

#endif

                                                ////////////////////////////////////////////
                                                //                TASK 2                  //
                                                ////////////////////////////////////////////
#ifdef TASK2

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
     Because in the class there is no special copy constructor that would create a dynamic copy of the value parameter. After the function, the 
     destructor is called that destroys the original content where it was pointed to, thus the programme is printing garbage and then tries to 
     release the same memory for the second time which leads to the crash of the programme. 
   _____________________________________________________________________________________________________________________________________________ */

#endif

                                                ////////////////////////////////////////////
                                                //                TASK 3                  //
                                                ////////////////////////////////////////////
#ifdef TASK3

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

#endif

                                                ////////////////////////////////////////////
                                                //                TASK 4                  //
                                                ////////////////////////////////////////////
#ifdef TASK4

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

#endif

                                                ////////////////////////////////////////////
                                                //          EXTRA TASK /TASK 5            //
                                                ////////////////////////////////////////////
#ifdef TASK5

class String {

public:

    String(const char* string) {
        c_string = new char[strlen(string) + 1];
        strcpy(c_string, string);
    }

    String(const String& s) {
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

    char* c_string;

};

void f(int i) {
    String s("abcdefghijklmnopqrstuvwxyz");
    s.list();
}

int main() {
    int i = 0;
    _CrtMemState memory; // C/C++ runtime memory management state storage
    while (i < 3) {
        f(i++);
        // dump memory management state
        _CrtMemCheckpoint(&memory); _CrtMemDumpStatistics(&memory);
    }
    _CrtDumpMemoryLeaks(); // check if there were memory leaks
    return 0;
}

/* _____________________________________________________________________________________________________________________________________________
     How many bytes is that fixed amount? Why the amount of bytes is that?
   ---------------------------------------------------------------------------------------------------------------------------------------------
     By removing the destructor, the programme leaks 27 bytes per each "abcdefghijklmnopqrstuvwxyz" instances (3 times 27 bytes overall).
     16 bytes originates from the string as 1 character equals 1 byte typically in C++. The additional 9 bytes are related to the activity of
     memory allocation, such as memory management bookkeeping.

     Example output:
     ---------------
     Detected memory leaks!
     Dumping objects ->
     {159} normal block at 0x00000153B657CBD0, 27 bytes long.
     Data: <abcdefghijklmnop> 61 62 63 64 65 66 67 68 69 6A 6B 6C 6D 6E 6F 70
     {158} normal block at 0x00000153B657D470, 27 bytes long.
     Data: <abcdefghijklmnop> 61 62 63 64 65 66 67 68 69 6A 6B 6C 6D 6E 6F 70
     {156} normal block at 0x00000153B657C930, 27 bytes long.
     Data: <abcdefghijklmnop> 61 62 63 64 65 66 67 68 69 6A 6B 6C 6D 6E 6F 70
     Object dump complete.
   ____________________________________________________________________________________________________________________________________________
     Why the destructor solves the memory leak problem? Why in this case you need to write a special destructor?
   ---------------------------------------------------------------------------------------------------------------------------------------------
     Destructor frees the memory blocks that were allocated dynamically, thus preventing possible memory leakages. A special destructor needs to
     be implemeted if dynamic memory allocation is used.
   _____________________________________________________________________________________________________________________________________________ */

#endif
