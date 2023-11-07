/*
Write a function:
void reverse(int *t, int n);
which reverses the values in the given arrayto opposite order (n is the size of the array).
*/

#include <iostream>

using namespace std;

void reverse(int *t, int n);

int main() {
  
  int task3_array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int task3_arr_size = sizeof(task3_array)/sizeof(task3_array[0]);

  cout << "Original array: ";
  for(int i = 0; i < task3_arr_size; i++) {
    cout << task3_array[i] << " ";
  }
  cout << endl;

  reverse(task3_array, task3_arr_size);

  cout << "Reversed array: ";
  for(int i = 0; i < task3_arr_size; i++) {
    cout << task3_array[i] << " ";
  }

  return 0;
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
