#include <iostream>

////////////////////// JARKKO /////////////////////
#define TASK1 // Define selected task (TASK1-TASK9)
///////////////////////////////////////////////////

using namespace std;

                        ////////////////////////////////////////////
                        //               TASK 1                   //
                        ////////////////////////////////////////////
#ifdef TASK1

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

#endif

                        ////////////////////////////////////////////
                        //               TASK 2                   //
                        ////////////////////////////////////////////
#ifdef TASK2

void read_values(int *t, int n);

int main() {

    int n;
    cout << "Enter the number of integers to be read: ";
    cin >> n;
    int task2_array[n];
    read_values(task2_array, n);

    cout << "Entered array of " << n << " integers: ";
    for(int i = 0; i < n; i++) {
        cout << task2_array[i] << " ";
    }

    return 0;
}

void read_values(int *t, int n) {

    for (int i = 0; i < n; i++) {
        cout << "Enter number: ";
        cin >> *t;
        t++;
    }
}

#endif

                        ////////////////////////////////////////////
                        //               TASK 3                   //
                        ////////////////////////////////////////////
#ifdef TASK3

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

#endif

                        ////////////////////////////////////////////
                        //               TASK 4                   //
                        ////////////////////////////////////////////
#ifdef TASK4

void print_values(const int *t, int n);

int main() {

    int task4_array[] = {23, 24, 25, 26, 27, 28, 29, 30, 31, 32};
    int task4_arr_size = sizeof(task4_array) / sizeof(task4_array[0]);

    cout << "Printing array with a function: " << endl;
    print_values(task4_array, task4_arr_size);

    return 0;

}

void print_values(const int *t, int n) {

    for (int i = 0; i < n; i++) {
        cout << *t << " ";
        t++;
    }
}

#endif

                        ////////////////////////////////////////////
                        //               TASK 5                   //
                        ////////////////////////////////////////////
#ifdef TASK5

int *allocate_table(int n);
void read_values(int *t, int n);
void reverse(int *t, int n);
void print_values(const int *t, int n);

int main() {

    int array_size;

    cout << "Enter the number of array elements: ";
    cin >> array_size;

    int *array_ptr = allocate_table(array_size);

    if (array_ptr != nullptr) {
        read_values(array_ptr, array_size);
        reverse(array_ptr, array_size);
        cout << "The array of " << array_size << " integers printed out reversed: " << endl;
        print_values(array_ptr, array_size);
        delete array_ptr;
    } else {
        cout << "The array initiation was unsuccessful." << endl;
    }

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

void read_values(int *t, int n) {

    for (int i = 0; i < n; i++) {
        cout << "Enter number: ";
        cin >> *t;
        t++;
    }
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

void print_values(const int *t, int n) {

    for (int i = 0; i < n; i++) {
        cout << *t << " ";
        t++;
    }
}

#endif
                        ////////////////////////////////////////////
                        //               TASK 6                   //
                        ////////////////////////////////////////////
#ifdef TASK6

void read_values();
void reverse();
void print_values();

int n;
int *array_ptr;

int main() {

    cout << "Enter the number of array elements: ";
    cin >> n;

    array_ptr = new int [n];

    read_values();
    reverse();
    cout << "The array of " << n << " integers printed reversed: " << endl;
    print_values();
    delete array_ptr;

    return 0;

}

void read_values() {

    for (int i = 0; i < n; i++) {
        cout << "Enter number: ";
        cin >> array_ptr[i];
    }
}

void reverse() {

    int *left = array_ptr;
    int *right = &array_ptr[n - 1];

    while (left < right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
        left++;
        right--;
    }
}

void print_values() {

    for (int i = 0; i < n; i++) {
        cout << array_ptr[i] << " ";
    }
}

#endif

                        ////////////////////////////////////////////
                        //               TASK 7                   //
                        ////////////////////////////////////////////
#ifdef TASK7

class Node {
public:
    int data;
    Node *next;
};

void print_list(const Node *head);

int main() {

    Node *s4 = new Node;
    s4->data = 1; s4->next = nullptr;
    Node *s3 = new Node;
    s3->data = 2; s3->next = s4;
    Node *s2 = new Node;
    s2->data = 10; s2->next = s3;
    Node *s1 = new Node;
    s1->data = 3; s1->next = s2;
    Node *head = s1;

    cout << "Printing integer linked list: " << endl;
    print_list(head);

    return 0;
}

void print_list(const Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

#endif
                        ////////////////////////////////////////////
                        //               TASK 8                   //
                        ////////////////////////////////////////////
#ifdef TASK8

class Node {
public:
    int data;
    Node *next;
};

void print_list(const Node *head);
Node *insert_first(Node *head, int value);

int main() {

    Node *s4 = new Node;
    s4->data = 1; s4->next = nullptr;
    Node *s3 = new Node;
    s3->data = 2; s3->next = s4;
    Node *s2 = new Node;
    s2->data = 10; s2->next = s3;
    Node *s1 = new Node;
    s1->data = 3; s1->next = s2;
    Node *head = s1;

    cout << "Original list: " << endl;
    print_list(head);

    head = insert_first(head, 5);
    cout << "The array with new, inserted head: " << endl;
    print_list(head);

    return 0;
}

void print_list(const Node *head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *insert_first(Node *head, int value) {
    Node *new_head = new Node;
    new_head->data = value; new_head->next = head;
    head = new_head;
    return head;
}

#endif
                        ////////////////////////////////////////////
                        //               TASK 9                   //
                        ////////////////////////////////////////////
#ifdef TASK9

class Node {
public:
    int data;
    Node *next;
};

void print_list(const Node *head);
Node *insert_first(Node *head, int value);
void delete_list(Node *head);

int main() {

    Node *s4 = new Node;
    s4->data = 1; s4->next = nullptr;
    Node *s3 = new Node;
    s3->data = 2; s3->next = s4;
    Node *s2 = new Node;
    s2->data = 10; s2->next = s3;
    Node *s1 = new Node;
    s1->data = 3; s1->next = s2;
    Node *head = s1;

    cout << "Original list: " << endl;
    print_list(head);

    head = insert_first(head, 5);
    cout << "The array with new, inserted head: " << endl;
    print_list(head);

    delete_list(head);

    return 0;
}

void print_list(const Node *head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *insert_first(Node *head, int value) {
    Node *new_head = new Node;
    new_head->data = value; new_head->next = head;
    head = new_head;
    return head;
}

void delete_list(Node *head) {
    cout << "Being deleted: " << endl;
    while (head != nullptr) {
        Node *ptr = head->next;
        cout << head->data << " ";
        delete head;
        head = ptr;
    }
    cout << endl;
}

#endif
