/*
Write a function:
int *allocate_table(int n);
which reserves an integer array of the given size (n). Function returns a pointer to the beginning of the table.
*/

#include <iostream>

using namespace std;

int *allocate_table(int n);

int main() {

    int array_size;

    cout << "Enter the number of array elements: ";
    cin >> array_size;

    int *array_ptr = allocate_table(array_size);

    if (array_ptr != nullptr) {
        cout << "The memory address of first array element: " << array_ptr << endl;
    } else {
        cout << "The array initiation was unsuccessful." << endl;
    }

    delete array_ptr;

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
