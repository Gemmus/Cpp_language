#include "counter.h"
#include <iostream>

/////////////////////////// JARKKO ////////////////////////////
#define TASK7E // Define selected task (TASK7A, TASK7B, TASK7E)
///////////////////////////////////////////////////////////////

using namespace std;

/**************************
 *        TASK  7A        *
 **************************/

#ifdef TASK7A

class LimitedCounter {
    friend ostream& operator<<(ostream& output, const LimitedCounter& c1) {
        output << "" << c1.counter << "";
        return output;
    }

public:
    LimitedCounter(int n0=0, int n1=100):counter(n0), upper_limit(n1) {}

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
    cout << "\nlc.getCount(): " << lc.getCount() << endl; //output is 5
    cout << "\n(lc < 7): " << (lc < 7) << endl; //Testing the comparison operator //output is 1
    cout << "\n(lc < 1): " << (lc < 1) << endl; //Testing the comparison operator //output is 0
    return 0;
}

#endif

/**************************
 *        TASK  7B        *
 **************************/

#ifdef TASK7B

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

#endif

/**************************
 *        TASK  7E        *
 **************************/

#ifdef TASK7E

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

#endif
