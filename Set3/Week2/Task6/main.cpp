/*
Find information about the sizeof operator. Then write a program that prints to the screen
how much space (how many bytes) the following types of variables take up in memory:
• int
• unsigned int
• float
• double
• char
• bool
*/

#include <iostream>

using namespace std;

int main() {

   int int_num; // Size: 4 bytes
   cout << "The size of an integer is: " << sizeof(int_num) << " bytes." << endl;

   unsigned int uint_num; // Size: 4 bytes
   cout << "The size of an unsigned integer is: " << sizeof(uint_num) << " bytes." << endl;

   float float_num; // Size: 4 bytes
   cout << "The size of a float is: " << sizeof(float_num) << " bytes." << endl;

   double double_num; // Size: 8 bytes
   cout << "The size of a double is: " << sizeof(double_num) << " bytes." << endl;

   char character; // Size: 1 bytes
   cout << "The size of a character is: " << sizeof(character) << " bytes." << endl;

   bool istrue; // Size: 1 bytes
   cout << "The size of a boolean is: " << sizeof(istrue) << " bytes." << endl;

   return 0;
}
