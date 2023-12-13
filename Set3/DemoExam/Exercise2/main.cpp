/*
Let’s assume that the class Person contains the first name and the last name of a person and it is
defined in the following way:

class Person {
public:
 //public member functions
 //
private:
 string first_name;
 char* last_name;
};

As we can see from the definition of the class, the first_name is stored as a C++-string object and
and the last_name is a pointer so that the characters of the last name are stored in dynamic
memory. We now want that Person class can be used in the following way:

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

Remark. If you are wondering the meaning of plus operator in this context, think of sending a
Christmas card to a couple Pekka Peltonen and Bertta Peltonen. The plus operator gives the result
you can use in the name field of the post card.
Write the complete definition for the class Person and implement all functions so that
the program above becomes a valid and working program. It is required that there is no
memory leaks when the program is run. (6p)
*/
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
    Person (const string &fn="",const char *ln="") {
        first_name = fn;
        last_name = new char[strlen(ln) + 1];
        strcpy(last_name, ln);
    }
    Person(const Person &p) {
        first_name = p.first_name;
        last_name = new char[strlen(p.last_name) + 1];
        strcpy(last_name, p.last_name);
    }
    ~Person() {
        delete last_name;
    }

    Person& operator=(const Person &right) {
        if (this != &right) {
            delete last_name;
            last_name = new char[strlen(right.last_name) + 1];
            strcpy(last_name, right.last_name);
            first_name = right.first_name;
        }
        return *this;
    }

    Person operator+(const Person &p2) const {
        Person couple = *this;
        couple.first_name = this->first_name + " & " + p2.first_name;
        return couple;
    }

private:
    string first_name;
    char* last_name;
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



