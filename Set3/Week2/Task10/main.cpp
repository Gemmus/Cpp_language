/*
What is the value of the variable x after the execution of each line of the program?
value of x
1 int x = 15;
2 int *y;
3 y = &x;
4 *y = *y + 3;
5 int z = 2;
6 int *w;
7 w = y;
8 y = 0;
9 y = &z;
10 *w = *w + *y;
11 int t[] = { 9, 10 };
12 y = t;
13 *w += *y;
14 y++;
15 *w += *y;
*/

#include <iostream>

using namespace std;

int main() {

    int counter = 1;

    // 1: 15
    int x = 15;
    cout << counter << ": " << x << endl;
    counter++;

    // 2: 15
    int *y;
    cout << counter << ": " << x << endl;
    counter++;

    // 3: 15
    y = &x; // y pointing to x memory address; *y = 15
    cout << counter << ": " << x << endl;
    counter++;

    // 4: 18
    *y = *y + 3; // *y = 15 + 3
    cout << counter << ": " << x << endl;
    counter++;

    // 5: 18
    int z = 2; 
    cout << counter << ": " << x << endl;
    counter++;

    // 6: 18
    int *w;
    cout << counter << ": " << x << endl;
    counter++;

    // 7: 18
    w = y; // w points to x; *w = 18
    cout << counter << ": " << x << endl;
    counter++;

    // 8: 18
    y = 0;
    cout << counter << ": " << x << endl;
    counter++;

    // 9: 18
    y = &z; // y points to z memory address, *y = 2
    cout << counter << ": " << x << endl;
    counter++;

    // 10: 20
    *w = *w + *y;  // *w = 18 + 2
    cout << counter << ": " << x << endl;
    counter++;

    // 11: 20
    int t[] = {9, 10};
    cout << counter << ": " << x << endl;
    counter++;

    // 12: 20
    y = t; // *y = 9
    cout << counter << ": " << x << endl;
    counter++;

    // 13: 29
    *w += *y; // *w = 20 + 9
    cout << counter << ": " << x << endl;
    counter++;

    // 14:
    y++; // *y = 10
    cout << counter << ": " << x << endl;
    counter++;

    // 15: 39
    *w += *y;  // 29 + 10
    cout << counter << ": " << x << endl;
    
   return 0;
}
