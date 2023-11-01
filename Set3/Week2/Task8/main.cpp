/*
Write a program that calculates the length of a C string of characters. A C-string is a char
table with the special character '\0' as the 'terminator'. This can be introduced for testing
purposes, e.g. by using the following example.
char str[] = “Hello”;
The last character of the string defined above will automatically be '\0', and its length will
be 5 characters.
Do not use the library function strlen().
*/  

#include <iostream>

using namespace std;

int main() {

   char str[] = "Hello";
   int i = 0;

   while (str[i] != '\0') { // i = 5 when str[i] == '\0'
       cout << "The memory address of str[" << i << "] / ('" << str[i] <<  "') is: " << (void*) &str[i] << endl;
       i++;
   }

    cout << "The memory address of str[" << i << "] / ('\\0') is: " << (void*) &str[i] << endl;

   cout << "The length of str[] is: " << i << endl;

   return 0;
}
