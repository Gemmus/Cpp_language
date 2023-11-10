/*
Write a function which add a new node to the beginning of the list. Function returns pointer to the new head of the list.
Node *insert_first(Node *head, int value);
Note!: if the list does not exist yet (head == nullptr), a totally new node must be created. Use new -operator to allocate memory.
*/

#include <iostream>

using namespace std;

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
