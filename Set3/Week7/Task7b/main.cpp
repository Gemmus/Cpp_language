/*
Excercise 7b (Inheritance)
-----------------------------------------------------------------------------------------------------------------------
Both the “is part of” relation and inheritance relation are ways to reuse classes (or objects) in software development.
It is not always easy to decide should we use “part of relation” or inheritance relation. A good rule is that you
should choose the relation that most naturally suits the situation.

If you naturally can think that an object really is a part of another object, you should choose “part of” relation
(for example a date (representing a birthday) is part of personal data). If you naturally think that an object is a
general case of another object, then you should choose inheritance relation (for example vehicle is a more general
concept than truck). As said before, the making decision is not always clear and both relations are useful.

You have already implemented a limited counter using “part of relation” in the exercise 7a. Implement class
LimitedCounter now using inheritance relation. In this case the inheritance relation is better, because this new counter
clearly is a special case of basic counter.

Remark. The basic idea in reuse is that the software component can be reused as a black box without modifying
its source code.
*/

#include "counter.h"
#include <iostream>

using namespace std;

class LimitedCounter: public Counter {
public:
    explicit LimitedCounter(int n0=0, int n1=100):Counter(n0) {
        upper_limit = n1;
    }

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

int main() {
    LimitedCounter lc(3, 5); //initial value 3, upper limit 5
    cout << lc++ << endl; //output should be 3
    cout << ++lc << endl; //output should be 5
    lc.reset();
    for (int i = 0; i < 9; i++) {
        ++lc;
        cout << lc << endl; //output is 1 2 3 4 5 5 5 5 5
    }
    cout << "lc.getCount(): " << lc.getCount() << endl; //output is 5
    cout << "(lc < 7): " << (lc < 7) << endl; //Testing the comparison operator //output is 1
    cout << "(lc < 1): " << (lc < 1) << endl; //Testing the comparison operator //output is 0
    return 0;
}
