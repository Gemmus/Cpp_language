#include <string>
#include <iostream>
#include <string.h>

using namespace std;

class Person {
    friend ostream& operator<<(ostream &out, const Person &pPtr) {
        out << pPtr.first_name << " " <<  pPtr.last_name;
        return out;
    }

public:
    Person (const char *fn="",const string &ln="") {
        last_name = ln;
        first_name = new char[strlen(fn) + 1];
        strcpy(first_name, fn);
    }
    Person(const Person &p) {
        last_name = p.last_name;
        first_name = new char[strlen(p.first_name) + 1];
        strcpy(first_name, p.first_name);
    }
    ~Person() {
        delete first_name;
    }

    Person& operator=(const Person &right) {
        if (this != &right) {
            delete first_name;
            first_name = new char[strlen(right.first_name) + 1];
            strcpy(first_name, right.first_name);
            last_name = right.last_name;
        }
        return *this;
    }

    Person operator+(const Person &p2) const {
        Person couple = *this;
        couple.first_name = new char[strlen(first_name) + strlen(p2.first_name) + 4];
        strcpy(couple.first_name, first_name);
        strcat(couple.first_name, " & ");
        strcat(couple.first_name, p2.first_name);
        return couple;
    }

private:
    char* first_name;
    string last_name;
};

int main() {

    Person p1("Pekka", "Peltonen"), p2("Bertta", "Peltonen"), couple;
    couple = p1 + p2; // Constructs a name where last name is from p1 and first
    //name is a combination of the first names of p1 and p2.
    //In this particular case “the first name” of p3 becomes
    //”Pekka & Bertta” and the last name becomes “Peltonen”.
    cout << couple; //Person couple is displayed (first name and last
    //name) on the screen. In this case the output is
    //”Pekka & Bertta Peltonen”
    return 0;
}
