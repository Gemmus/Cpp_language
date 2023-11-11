/*
Write a function which is given a pointer to the start of a linked list, and which prints out
the content of the list by traversing the list one-by-one:
void print_list(const Node *head);
When testing your function, it should give the output 3, 10, 2, 1 when using the given example of list creation.
*/

#include <iostream>

using namespace std;

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
