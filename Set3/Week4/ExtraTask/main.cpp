/*
In phase 1 you were asked to write the destructor function for the class. It is necessary to
avoid memory leaks. You can demonstrate the memory leak for yourself by removing the
destructor from the last version (phase 4) and using the class in the program below.

When this program is running follow its memory consumption. Visual Studio has a few
run-time debugging features (declared in crtdbg.h). The program below uses them to write
to the special Visual Studio output window (look for the separate ‘Output’ window on
Visual Studio) information about dynamic memory usage. Notice that the memory allocated
increases all the time by fixed amount from output to the next output (look for the ‘Normal
blocks’ row). How many bytes is that fixed amount? Why the amount of bytes is that?

After you have found the memory leak problem, put the destructor back to the String class
and rerun the program. Ensure that there are no memory leaks anymore. Why the destructor
solves the memory leak problem? Why in this case you need to write a special destructor?
Notice that _CrtDumpMemoryLeaks() at the end of the program does not report anything
if there are no memory leaks.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#ifdef _DEBUG                   // Active only in Debug Configuration
#define _CRTDBG_MAP_ALLOC       // Visual Studio Mem Leak detector activated
#include <crtdbg.h>             // runtime debug functions are declared here
#endif

using namespace std;

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
