/*   Function objects

Goal of this exercise is to use STL iterators and algorithms and to learn how function objects work.

Modify and improve the random number generator from the lecture slides (lecture7, page 27) to create a lotto number
generator:

Constructor must take two parameters (min and max) that determine the range of numbers that the generator produces.

You may not write any for-loops in this exercise. Use only STL-algorithms!

Write a program that generates numbers for three different games:
    1. Lotto: 7 numbers 1 – 40
    2. Viking lotto: 6 numbers 1 – 48
    3. Eurojackpot: 5 numbers 1 – 50

Use either generate or generate_n algorithm to generate the three sets of numbers.
Print each set of numbers using a suitable algorithm and output stream iterator.

Then find numbers that appear in all three sets and print them. Use set_intersection
algorithm to find the numbers that appear in all three sets:
    • Find matching numbers from two sets and print them using for_each algorithm
    • Find matching number from the third set and print them using for_each algorithm. Note that it is very unlikely to
      get matches in all three sets, so you need to run multiple tests to see a match

To print the numbers with index numbering you must use a function object to remember the index between calls.

Example:
    Lotto: 1 12 24 36 11 15 32
    Viking lotto: 24 7 11 18 35 1
    Matching numbers:
    #1: 1
    #2: 11
    #3: 24
    Eurojackpot: 47 1 40 24 4
    Matching numbers in three sets:
    #1: 1
    #2: 24

After finding the matching numbers ask user if they want to continue. If the answer is yes
then generate another three sets of lotto numbers.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#define ALL_MIN 1
#define LOTTO_MAX 40
#define LOTTO_N 7
#define VIKING_LOTTO_MAX 48
#define VIKING_LOTTO_N 6
#define EUROJACKPOT_MAX 50
#define EUROJACKPOT_N 5

using namespace std;

class RandomGenerator {
public:
    RandomGenerator(int min0, int max0) {
        min = min0;
        max = max0;
    }

    int operator()() {
        int number;
        do {
            number = rand() % max + min;
        } while(find(numbers.begin(), numbers.end(), number) != numbers.end());
        numbers.push_back(number);
        return number;
    }

private:
    int min;
    int max;
    vector<int> numbers;
};

class CountPrinter {
public:
    CountPrinter() {
        count = 0;
    }

    void operator()(int num) {
        cout << "\n#" << ++count << ": " << num;
    }

private:
    int count;
};

int main() {
    srand(time(nullptr));

    vector<int> lottoVector(LOTTO_N);
    vector<int> vikinglottoVector(VIKING_LOTTO_N);
    vector<int> eurojackpotVector(EUROJACKPOT_N);
    vector<int> matchingTwo;
    vector<int> matchingAllThree;

    // Generating Lotto numbers:
    generate(lottoVector.begin(), lottoVector.end(), RandomGenerator(ALL_MIN, LOTTO_MAX));
    cout << "Lotto: ";
    copy(lottoVector.begin(), lottoVector.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    // Generating Viking lotto numbers:
    generate(vikinglottoVector.begin(), vikinglottoVector.end(), RandomGenerator(ALL_MIN, VIKING_LOTTO_MAX));
    cout << "Viking lotto: ";
    copy(vikinglottoVector.begin(), vikinglottoVector.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    // Matching numbers of lotto and viking lotto:
    sort(lottoVector.begin(), lottoVector.end());
    sort(vikinglottoVector.begin(), vikinglottoVector.end());
    set_intersection(lottoVector.begin(), lottoVector.end(), vikinglottoVector.begin(), vikinglottoVector.end(), back_inserter(matchingTwo));
    cout << "Matching numbers:";
    for_each(matchingTwo.begin(), matchingTwo.end(), CountPrinter());
    cout << endl;

    // Generating EuroJackPot numbers:
    generate(eurojackpotVector.begin(), eurojackpotVector.end(), RandomGenerator(ALL_MIN, EUROJACKPOT_MAX));
    cout << "EuroJackPot: ";
    copy(eurojackpotVector.begin(), eurojackpotVector.end(), ostream_iterator<int> (cout, " "));
    cout << endl;

    // Matching numbers of all three:
    sort(eurojackpotVector.begin(), eurojackpotVector.end());
    set_intersection(matchingTwo.begin(), matchingTwo.end(), eurojackpotVector.begin(), eurojackpotVector.end(), back_inserter(matchingAllThree));
    cout << "Matching numbers in three sets:";
    for_each(matchingAllThree.begin(), matchingAllThree.end(), CountPrinter());
    cout << endl;

    return 0;
}
