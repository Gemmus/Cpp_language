/*  Composition

Implement a class for calculating running average of a number of values. The idea of running average that average is
calculated of last N values. For example, when running average of last 10 values is calculated everytime a new value is
added if there are already 10 values the oldest value is removed.

Implement a class called RunningAverage:
• Constructor takes number of values as a parameter for example:
       RunningAverage avg(5);
  Creates an instance that remember five last values.
• A deque of integers is used to store the values
• Class has member funcIon void add_value(int value) which is used to add a new value and to remove the oldest value if
  there are specified number of elements so that number of values in the never exceeds the size given in the constructor.
• Class has member funcIon double get_average() that returns the average of the stored values.

Write a program that creates running average object to calculate running average of last five numbers. Program asks user
to enter numbers and to enter zero to stop. If entered value is not zero it is added to the running average and program
prints the current running average. If value is zero the program prints the current running average and then stops.
*/

#include <iostream>
#include <deque>
#include <sstream>
#include <string>

using namespace std;

class RunningAverage {
public:
    RunningAverage(int maxSize0=0) {
        maxSize = maxSize0;
        sum = 0;
    }

    double add_value(int value) {
        values.push_back(value);
        sum += value;

        if (values.size() > maxSize) {
            sum -= values.front();
            values.pop_front();
        }
    }

    double get_average() const {
        if (values.empty()) {
            return 0.0;
        }
        return (double)sum/(double)values.size();
    }

private:
    int maxSize;
    int sum;
    deque<int> values;
};

int main() {

    int maxSize, aux;
    string input;
    bool to_stop = false;

    cout << "Enter the max size: ";
    cin >> maxSize; cin.ignore(1);

    RunningAverage average(maxSize);

    while (!to_stop) {
        cout << "Enter value or \"ave\" to print average or \"stop\" to exit: ";
        getline(cin, input);
        if (input == "ave") {
            cout << "Average: " << average.get_average() << endl;
        } else if (input == "stop") {
            to_stop = true;
        } else {
            istringstream is(input);
            is >> aux;
            average.add_value(aux);
        }
    }

    return 0;
}
