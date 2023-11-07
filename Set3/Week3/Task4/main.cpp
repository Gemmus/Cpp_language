/*
Write a functions: 
void print_values(const int *t, int n);
which prints the content of the given array to the screen (n is the size of the array). 
const means that the function is not allowed to change the content of the given array.
*/

#include <iostream>

using namespace std;

void print_values(const int *t, int n);

int main() {

    int task4_array[] = {23, 24, 25, 26, 27, 28, 29, 30, 31, 32};
    int task4_arr_size = sizeof(task4_array) / sizeof(task4_array[0]);

    print_values(task4_array, task4_arr_size);

    return 0;

}

void print_values(const int *t, int n) {
    for (int i = 0; i < n; i++) {
        cout << *t << " ";
        t++;
    }
}
