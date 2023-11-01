/*
Write a function that returns a pointer to the largest integer in the table given as a parameter.
As a parameter it is given as both a pointer to the first element of the table and information
about how the number of elements in the table:
int *find_largest(const int *table, int table_len);
Test also your function.
*/

#include <iostream>

using namespace std;

int *find_largest(const int *table, int table_len);

int main() {

   int number_array[] = { 255, 268, 968, 125, 69, 648, 13, 54};
   int array_length = sizeof(number_array) / sizeof(number_array[0]);

   int *largestPtr = find_largest(number_array, array_length);

   if (largestPtr == NULL) {
       cout << "Invalid input or array is empty." << endl;
   } else {
       cout << "The largest number of the array is: " << *largestPtr << endl;
   }

   return 0;
}

int *find_largest(const int *table, int table_len) {

    if(table == NULL || table_len == 0) {
        return NULL;
    }

    const int *largest = table;

    for(int i = 1; i < table_len; i++) {
        if (*largest < table[i]) {
            largest = &table[i];
        }
    }
    return (int *)largest;
}

