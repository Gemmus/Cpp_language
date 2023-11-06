/*
Write a function:
void read_values(int *t, int n);
which reads to the array given as a parameter integers from the keyboard (n is the size of the array).
*/

#include <iostream>

using namespace std;

void read_values(int *t, int n);

int main() {

    int n;
    cout << "Enter the number of integers to be read: ";
    cin >> n;
    int task2_array[n];
    read_values(task2_array, n);

    cout << "Entered array of integers: ";
    for(int i = 0; i < n; i++) {
        cout << task2_array[i] << " ";
    }

    return 0;
}

void read_values(int *t, int n) {

    for (int i = 0; i < n; i++) {
        cout << "Enter number: ";
        cin >> *t;
        t++;
    }
}
