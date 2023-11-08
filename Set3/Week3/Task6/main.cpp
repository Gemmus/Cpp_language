/*
Modify the program from the task 5 in such a way that functions does not get the pointer to the array and its size as a separate parameter, instead they are global variables.
void read_values();
void reverse();
void print_values();
*/

#include <iostream>

using namespace std;

void read_values();
void reverse();
void print_values();

int n;
int *array_ptr;

int main() {

    cout << "Enter the number of array elements: ";
    cin >> n;

    array_ptr = new int [n];

    read_values();
    reverse();
    cout << "The array of " << n << " integers printed reversed: " << endl;
    print_values();
    delete array_ptr;

    return 0;

}

void read_values() {

    for (int i = 0; i < n; i++) {
        cout << "Enter number: ";
        cin >> array_ptr[i];
    }
}

void reverse() {

    int *left = array_ptr;
    int *right = &array_ptr[n - 1];

    while (left < right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
        left++;
        right--;
    }
}

void print_values() {

    for (int i = 0; i < n; i++) {
        cout << array_ptr[i] << " ";
    }
}
