/*
Write a main function which asks from the user the size of the integer array, then reads from the keyboard the content of the array,
rearranges the content of the array to opposite order, and finally prints out the content of the array to the display.
Program created should utilize the functions written in tasks 1 – 4.
*/

#include <iostream>

using namespace std;

int *allocate_table(int n);
void read_values(int *t, int n);
void reverse(int *t, int n);
void print_values(const int *t, int n);

int main() {

    int array_size = 0;

    cout << "Enter the number of array elements: ";
    cin >> array_size;

    int *array_ptr = allocate_table(array_size);

    if (array_ptr != nullptr) {
        read_values(array_ptr, array_size);
        reverse(array_ptr, array_size);
        cout << "The array of " << array_size << " integers printed out reversed: " << endl;
        print_values(array_ptr, array_size);
        delete array_ptr;
    } else {
        cout << "The array initiation was unsuccessful." << endl;
    }

    return 0;

}

int *allocate_table(int n) {

    if (n <= 0) {
        return nullptr;
    }

    int *array;
    array = new int [n];

    return &array[0];
}

void read_values(int *t, int n) {

    for (int i = 0; i < n; i++) {
        cout << "Enter number: ";
        cin >> *t;
        t++;
    }
}

void reverse(int *t, int n) {

    int *left = t;
    int *right = &t[n - 1];

    while (left < right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
        left++;
        right--;
    }
}

void print_values(const int *t, int n) {

    for (int i = 0; i < n; i++) {
        cout << *t << " ";
        t++;
    }
}
