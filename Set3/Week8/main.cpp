/*
Exercise 8 (Polymorphic function)
------------------------------------------------------------------------------------------------------------------------
You used inheritance and developed a special counter class LimitedCounter (in lab 7). The specialty is that
LimitedCounter has an upper limit. When upper limit has been reached the counter in a way stops and is not anymore
incremented. Sometimes another kind of special counter is needed. This is called roundup counter. Roundup counter also
has an upper limit, but it starts from the beginning (from zero) when upper limit has been reached. The milometer in
cars for example behaves like a roundup counter. Implement the class RoundupCounter so that you have two special counter
classes LimitedCounter and RoundupCounter.

The next step is to experience polymorphism using these two different special counters. Write a generic function
UseCounter, that takes two parameters. The first parameter is the counter and the second parameter is an integer that
tells how many times the counter should be incremented. The function is global (not a member function of any class).
The function increments the counter by using the pre-increment operator as many times as is determined by the second
parameter in a loop. The requirement is that it is possible to pass limited counter as well as roundup counter to the
same function (and it would be possible to pass even ordinary counter). The increment happens of course according to
the properties of the counter that was as a parameter.
 
Hint: A small modification is now needed in the definition of the base class Counter. Because
of that, the implementation of that class (counter.cpp) also needs a recompilation.
*/

#include "counter.h"
#include <iostream>

using namespace std;

class LimitedCounter: public Counter {
public:
    explicit LimitedCounter(int n0=0, int n1=100):Counter(n0), upper_limit(n1) {}

    LimitedCounter &operator++() {
        if (getCount() < upper_limit) {
            Counter::operator++();
        }
        return *this;
    }

    LimitedCounter operator++(int) {
        LimitedCounter old = *this;
        if (getCount() < upper_limit) {
            Counter::operator++(0);
        }
        return old;
    }

private:
    int upper_limit;
};

class RoundupCounter: public Counter {
public:
    explicit RoundupCounter(int n0=0, int n1=100):Counter(n0), upper_limit(n1) {}

    RoundupCounter &operator++() {
        if (getCount() == upper_limit) {
            reset();
        } else {
            Counter::operator++();
        }
        return *this;
    }

    RoundupCounter operator++(int) {
        RoundupCounter old = *this;
        if (getCount() == upper_limit) {
            reset();
        } else {
            Counter::operator++();
        }
        return old;
    }

private:
    int upper_limit;
};

void UseCounter(Counter* c, int times) {
    for (int i = 0; i < times; i++) {
        ++(*c);
    }
}

int main() {
    LimitedCounter counterA(0, 5);
    RoundupCounter counterB(0, 5);
    UseCounter(&counterA, 8); UseCounter(&counterB, 8);
    cout << "Counter A: " << counterA << endl; // output should be 5
    cout << "Counter B: " << counterB << endl; // output should be 2
    return 0;
}


