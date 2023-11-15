
#include <iostream>
#include <cstring>

using namespace std;

class String{

public:

    String(const char* string) {
#if 0
        uint32_t length = strlen(string);
        if (length > 10) {
            length = 10;
        }
        strncpy(c_string, string, length);
        c_string[length] = '\0';
#else
        c_string = new char[strlen(string)+1];
//        cout << &c_string << endl;
        strncpy(c_string, string, strlen(string));
#endif
    }

#if 1
    ~String() {
        delete c_string;
        cout << "destructor done" << endl;
    }
#endif
    void list() {
#if 0
        for (int i = 0; c_string[i] != '\0'; i++) {
            cout << c_string[i];
        }
        cout << endl;
#else
        cout << &c_string << endl;
        cout << c_string << endl;
#endif
    }

private:
#if 0
    char c_string[11];
#else
    char *c_string;
#endif
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
