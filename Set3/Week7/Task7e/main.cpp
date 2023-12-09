/*
Extra exercise 7e (Association relation)
------------------------------------------------------------------------------------------------------------------------
Do the same thing so that the limited counter owns the “ordinary” counter, i.e., the limited counter has a pointer to
the ordinary counter as a data member. In practice this also means that there are two separate objects in memory
(limited counter object and ordinary counter object). When limited counter object is constructed, the ordinary counter
object is created. When the limited counter object is deallocated, the ordinary counter object is deallocated too (in
the destructor of the limited counter). Therefore, both objects co-exists all the time in memory. This kind of ownership
association is in a way another kind of implementation of composition relation.

Remark 1. Use the same main function as in the mandatory to test the class.

Remark 2. The class now has a dynamic data member. Remember what you have learned
earlier about dynamic members.
*/

#include "counter.h"
#include <iostream>

using namespace std;

class LimitedCounter {

friend ostream& operator<<(ostream& output, const LimitedCounter& c1) {
    output << "\nCounter value is now " << c1.countPtr->getCount() ;
    return output;
}

public:
    LimitedCounter(int n0=0, int n1=100) {
        countPtr = new Counter(n0);
        upper_limit = n1;
    }

    LimitedCounter(const LimitedCounter &cp) {
        countPtr = new Counter(*cp.countPtr);
        upper_limit = cp.upper_limit;
    }

    ~LimitedCounter(){
        delete countPtr;
    }

    LimitedCounter operator++(int) {
        LimitedCounter old = *this;
        if (countPtr->getCount() < upper_limit) {
            (*countPtr)++;
        }
        return old;
    }

    LimitedCounter& operator++() {
        if (countPtr->getCount() < upper_limit) {
            ++(*countPtr);
        }
        return *this;
    }

    void reset() {
        countPtr->reset();
    }

    int getCount() const {
        return countPtr->getCount();
    }

    bool operator<(int c2) const {
        return (countPtr->getCount() < c2);
    }

private:
    Counter *countPtr;
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
    cout << "\nlc.getCount(): " << lc.getCount() << endl; //output is 5
    cout << "\n(lc < 7): " << (lc < 7) << endl; //Testing the comparison operator //output is 1
    cout << "\n(lc < 1): " << (lc < 1) << endl; //Testing the comparison operator //output is 0
    return 0;
}
