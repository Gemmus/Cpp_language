#include <iostream>
#include <bitset>

using namespace std;

void reverse(int *t, int n);

int main() {

    int task3_array[] = { 5, 7};
    int task3_arr_size = sizeof(task3_array)/sizeof(task3_array[0]);

    cout << "XOR operation: " << endl;
    cout << " 0 + 0 --> 0 " << endl;
    cout << " 0 + 1 --> 1 " << endl;
    cout << " 1 + 0 --> 1 " << endl;
    cout << " 1 + 1 --> 0 " << endl << endl;

    reverse(task3_array, task3_arr_size);

    return 0;
}

void reverse(int *t, int n) {

    int *left = t;
    int *right = &t[n - 1];

    while (left < right) {
        bitset<8> a(*left); bitset<8> b(*right);
        cout << "Original values: *left = (" << *left  << ") " << a << " *right = (" << *right << ") " << b << endl;

        *left ^= *right;
        bitset<8> c(*left); bitset<8> d(*right);
        cout << "First *left ^= *right: *left = (" << *left  << ") " << c << " *right = (" << *right << ") " << d << endl;

        *right ^= *left;
        bitset<8> e(*left); bitset<8> f(*right);
        cout << "Now *right ^= *left: *right = (" << *right << ") " << f << " *left = (" << *left  << ") " << e <<  endl;

        *left ^= *right;
        bitset<8> g(*left); bitset<8> h(*right);
        cout << "Final *left ^= *right: *left = (" << *left  << ") " << g << " *right = (" << *right << ") " << h << endl;

        left++;
        right--;
    }
}
