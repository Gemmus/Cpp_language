/*
Write a program with an integer-type variable x, and a pointer-type variable y that points
to x. Then print to the screen:
1. address of both variables in memory
2. the value of both variables
If necessary, find additional information to print the output.
*/

#include <iostream>

using namespace std;

int main() {

   int x = 324;
   int *y = &x;

   cout << "The address of x in memory: " << &x << endl;
   cout << "The address of y in memory: " << &y << endl;

   cout << "The value of x: " << x << endl;
   cout << "The value of y: " << *y << endl;

   cout << "Where y points to: " << y << endl;

   return 0;
}
