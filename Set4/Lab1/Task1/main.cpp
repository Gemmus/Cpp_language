/* Write a program that defines an empty vector of integers. Then program asks user how many numbers he/she wants to
enter. Then program asks user to enter the numbers one at a time and adds them to the vector. When all number have been
entered the program prints the numbers in the vector.
For example:
How many numbers do you want to enter? 4
Enter nr[1]: 23
Enter nr[2]: 12
Enter nr[3]: 4
Enter nr[4]: 5
You entered: 23, 12, 4, 5 */

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int input_num;

    cout << "How many numbers do you want to enter? ";
    cin >> input_num;
    vector <int> v;

    for (int i = 1; i <= input_num; i++) {
        int input;
        cout << "Enter nr[" << i << "]: ";
        cin >> input;
        v.push_back(input);
    }

    cout << "You entered: ";

    for (int i = 0; i < v.size(); i++) {
        if (i != (input_num - 1 )) {
            cout << v[i] << ", ";
        } else {
            cout << v[i];
        }
    }

    return 0;
}
