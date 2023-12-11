/*
Exercise 7a (Composition relation; Sub component / main component relation)
------------------------------------------------------------------------------------------------------------------------
Composition relation, association relation and inheritance relation all can be regarded as a method to reuse a class.
The basic idea in reuse is that the software component can be reused as such as a black box without modifying or even
seeing its source code. Things we only need from the class being reused are the header file (containing only class
definition) and the compiled implementation (object code).

There is a simple Counter class (counter.h, counter.cpp) with elementary counter features on the web (Oma portal).
The services (or features) of that class are not sufficient for you now, because you need a different counter that has
a user definable upper limit. This new feature means that when the upper limit has been reached, the counter stops, and
following increment operations have no effect anymore. The counter can still be reset, and after the reset it starts
from zero again. The upper limit can be set with the constructor and with the member function setLimit. The class name
of this new class is LimitedCounter. Implement the class LimitedCounter so that the ordinary counter is a subcomponent
in LimitedCounter object.

Remark 1. It is not allowed to modify the original Counter class.

Remark 2. The limited counter must work otherwise in a similar way to the original
counter. This means that the limited counter needs to “understand” all operations that are
defined for the original ordinary counter. One new feature in the interface of limited
counter is that the limit can also be set in the constructor.
*/

#include "counter.h"
#include <iostream>

using namespace std;

class LimitedCounter {
    friend ostream& operator<<(ostream& output, const LimitedCounter& c1) {
        output << "" << c1.counter << "";
        return output;
    }

public:
    LimitedCounter(int n0=0, int n1=100):counter(n0) {
        upper_limit = n1;
    }

    LimitedCounter operator++(int) {
        LimitedCounter old = *this;
        if (old < upper_limit) {
            counter++;
        }
        return old;
    }

    LimitedCounter& operator++() {
        if (counter < upper_limit) {
            ++counter;
        }
        return *this;
    }

    void reset() {
        counter.reset();
    }

    int getCount() const {
        return counter.getCount();
    }

    bool operator<(int c2) const {
        return (counter < c2);
    }

private:
    Counter counter;
    int upper_limit;
};

int main() {
    LimitedCounter lc(0, 5); //initial value 0, upper limit 5
    cout << lc++ << endl; //output should be 0
    cout << ++lc << endl; //output should be 2
    lc.reset();
    for (int i = 0; i < 9; i++) {
        lc++;
        cout << lc << endl; //output is 1 2 3 4 5 5 5 5 5
    }
    cout << "lc.getCount(): " << lc.getCount() << endl; //output is 5
    cout << "(lc < 7): " << (lc < 7) << endl; //Testing the comparison operator //output is 1
    cout << "(lc < 1): " << (lc < 1) << endl; //Testing the comparison operator //output is 0
    return 0;
}
