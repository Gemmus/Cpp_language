/*
Write a functions, which removes the given list from the memory.
Nodes are released onyby-one using the delete -operator. Test it.
void delete_list(Node *head);
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
    while (head != nullptr) {
        Node *ptr = head->next;
        cout << "Being deleted: " << head->data << endl;
        delete head;
        head = ptr;
    }
}
