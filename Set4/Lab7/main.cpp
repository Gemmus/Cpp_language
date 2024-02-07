/*     Inheritance

Implement Person class as defined below. The class simply holds a person’s name and prints it when needed.

class Person {
public:
    Person(const char *name = "nobody");
    virtual ~Person() = default;
    virtual void identity() const;
    virtual void interrogate();
private:
    std::string name;
};

Identity() prints the name of the person.
Interrogate() does nothing (empty body) in class Person.

Derive a Spy class from Person and add member function that can be used to set an alias for the spy.
                void set_identity(const char *alias);

Spy constructor must take three parameters: name of the spy, alias of the spy, and resistance. Resistance is an integer
that represents spy’s resistance to interrogation. Every time interrogate() is called resistance is decremented by one.
When resistance is greater than zero identity() prints alias of the spy instead of the real name. When resistance is zero
identity() prints both the real name and the alias of the spy.

Set_identity sets the spy’s alias.

Note that you must override identity() and interrogate() in class Spy.

The real name of the spy is inherited from the Person class. Spy adds a private member to
hold the alias that spy uses until resistance runs out.

(Test application was given for testing purpose.)
*/

#include <iostream>

class Person {
public:
    Person(const char* name = "nobody") : name(name) {}
    virtual ~Person() = default;
    virtual void identity() const {
        std::cout << "My name is: " << name << std::endl;
    }
    virtual void interrogate() {}
private:
    std::string name;
};

class Spy : public Person {
public:
    Spy(const char *name0 = "nobody", const char* alias0 = "nobody", int resistance0 = 0) : Person(name0), spyAlias(alias0), resistance(resistance0) {}
    
    ~Spy() = default;

    void set_identity(const char *alias) {
        this->spyAlias = alias;
    }

    void identity() const override {
        if (resistance == 0) {
            Person::identity();
            std::cout << "My alias is: " << spyAlias << std::endl;
        } else {
            std::cout << "My name is: " << spyAlias << std::endl;
        }
    }
    
    void interrogate() override {
        if (resistance > 0){
            resistance--;
        }
    }
    
private:
    std::string spyAlias;
    int resistance;
};

int main(int argc, char** argv) {

    Person agent("James Bond");
    Spy spy("Emilio Largo", "William Johnson", 3);
    Spy spy2("Ernst Blofield", "John Keats", 5);

    std::cout << std::endl << "Nice to meet you. ";
    agent.identity();

    for (int i = 0; i < 6; ++i) {
        std::cout << "Who are you?" << std::endl;
        spy.interrogate();
        spy.identity();
    }
    spy.set_identity("Bill Munny");
    spy.identity();

    std::cout << std::endl << "Nice to meet you. ";
    agent.identity();

    for (int i = 0; i < 6; ++i) {
        std::cout << "Who are you?" << std::endl;
        spy2.interrogate();
        spy2.identity();
    }

    return 0;
}
