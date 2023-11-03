#include <iostream>
#include <ctime>

#define MAX_INT 2147483647

/////////////////////// JARKKO /////////////////////
#define TASK1 // Define selected task (TASK1-TASK10)
////////////////////////////////////////////////////

using namespace std;

int *find_largest(const int *table, int table_len);

int main() {

                    ////////////////////////////////////////////
                    //               TASK 1                   //
                    ////////////////////////////////////////////
#ifdef TASK1

    int user_num = 0;

    cout << "Playing number game!" << endl;

    while (true) {
        cout << "Give a number: ";
        cin >> user_num;
        cout << "I won, mine is " << user_num + 1 << "!" << endl;
    }

#endif

                    ////////////////////////////////////////////
                    //               TASK 2                   //
                    ////////////////////////////////////////////
#ifdef TASK2

    int user_num = 0;
    bool playing = true;

    cout << "Playing number game!" << endl;

    while (playing) {
        cout << "Give a number: ";
        cin >> user_num;
        if (0 != user_num) {
            cout << "I won, mine is " << user_num + 1 << "!" << endl;
        } else {
            playing = false;
        }
    }

    cout << "You chose to quit by entering 0. Bye!" << endl;

#endif

                    ////////////////////////////////////////////
                    //               TASK 3                   //
                    ////////////////////////////////////////////
#ifdef TASK3

    int user_num = 0;
    bool playing = true;

    cout << "Playing number game!" << endl;

    while (playing) {
        cout << "Give a number: ";
        cin >> user_num;
        if (MAX_INT == user_num) {
            cout << "It is a tie." << endl;
        } else if (0 == user_num){
            playing = false;
        } else {
            cout << "I won, mine is " << user_num + 1 << "!" << endl;
        }
    }

    cout << "You chose to quit by entering 0. Bye!" << endl;

#endif

                    ////////////////////////////////////////////
                    //               TASK 4                   //
                    ////////////////////////////////////////////
#ifdef TASK4

    srand(time(nullptr));

    int min_value = 1;
    int max_value = 100;

    int comp_num = (rand() % max_value) + min_value;
    int user_num = 0;
    int counter = 0;
    bool guessed = false;

    // cout << "Comp_num = " << comp_num << endl;
    while (!guessed) {

        cout << "Guess a number (" << min_value << " - " << max_value << "): ";
        cin >> user_num;

        if (user_num > comp_num) {
            cout << "Too large!" << endl;
        } else if (user_num < comp_num) {
            cout << "Too small!" << endl;
        } else if ( user_num == comp_num) {
            guessed = true;
        }

        counter++;
    }

    cout << "Right! You made " << counter << " guesses." << endl;

#endif

                    ////////////////////////////////////////////
                    //               TASK 5                   //
                    ////////////////////////////////////////////
#ifdef TASK5

    srand(time(nullptr));

    int min_value = 0, max_value = 0;

    cout << "Enter the smallest value of the range: ";
    cin >> min_value;
    cout << "Enter the largest value of the range: ";
    cin >> max_value;

    int comp_num = (rand() % (max_value - min_value)) + min_value;
    int user_num = 0;
    int counter = 0;
    bool guessed = false;

    // cout << "Comp_num = " << comp_num << endl;

    while (!guessed) {

        cout << "Guess a number (" << min_value << " - " << max_value << "): ";
        cin >> user_num;

        if (user_num > comp_num) {
            cout << "Too large!" << endl;
        } else if (user_num < comp_num) {
            cout << "Too small!" << endl;
        } else if ( user_num == comp_num) {
            guessed = true;
        }

        counter++;
    }

    cout << "Right! You made " << counter << " guesses." << endl;

#endif

                    ////////////////////////////////////////////
                    //               TASK 6                   //
                    ////////////////////////////////////////////
#ifdef TASK6

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

#endif

                    ////////////////////////////////////////////
                    //               TASK 7                   //
                    ////////////////////////////////////////////
#ifdef TASK7

   int x = 324;
   int *y = &x;

   cout << "The address of x in memory: " << &x << endl;
   cout << "The address of y in memory: " << &y << endl;

   cout << "The value of x: " << x << endl;
   cout << "The value of y: " << *y << endl;

   cout << "Where y points to: " << y << endl;

#endif

                   ////////////////////////////////////////////
                   //               TASK 8                   //
                   ////////////////////////////////////////////
#ifdef TASK8

   char str[] = "Hello";
   int i = 0;

   while (str[i] != '\0') { // i = 5 when str[i] == '\0'
       cout << "The memory address of str[" << i << "] / ('" << str[i] <<  "') is: " << (void*) &str[i] << endl;
       i++;
   }

    cout << "The memory address of str[" << i << "] / ('\\0') is: " << (void*) &str[i] << endl;

   cout << "The length of str[] is: " << i << endl;

#endif

                    ////////////////////////////////////////////
                    //               TASK 9                   //
                    ////////////////////////////////////////////
#ifdef TASK9

   int number_array[] = { 255, 468, 968, 125, 23045, 69, 648, 13, 54, 6453};
   int array_length = sizeof(number_array) / sizeof(number_array[0]);

   int *largestPtr = find_largest(number_array, array_length);

   if (largestPtr == nullptr) {
       cout << "Invalid input." << endl;
   } else {
       cout << "The largest number of the array is: " << *largestPtr << endl;
   }

#endif

                    ////////////////////////////////////////////
                    //               TASK 10                  //
                    ////////////////////////////////////////////
#ifdef TASK10

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

    // 14: 29
    y++; // *y = 10
    cout << counter << ": " << x << endl;
    counter++;

    // 15: 39
    *w += *y;  // *w = 29 + 10
    cout << counter << ": " << x << endl;

    /* TASK10 as comment:
     * 1.   15
     * 2.   15
     * 3.   15
     * 4.   18
     * 5.   18
     * 6.   18
     * 7.   18
     * 8.   18
     * 9.   18
     * 10.  20
     * 11.  20
     * 12.  20
     * 13.  29
     * 14.  29
     * 15.  39
     */

#endif

   return 0;
}

int *find_largest(const int *table, int table_len) {

    if(table == nullptr || table_len <= 0) {
        return nullptr;
    }

    const int *largest = table;

    for(int i = 1; i < table_len; i++) {
        if (*largest < table[i]) {
            largest = &table[i];
        }
    }

    return (int *)largest;
}

