#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* CreateNode(int x);

void Insert_Begin(int x, Node*& head);


int main() {
    Node* head = NULL;

    return 0;
}

Node* CreateNode(int x) {
    Node* NewNode = new Node();
    NewNode->data = x;
    NewNode->next = NULL;
    NewNode->prev = NULL; 
    return NewNode;
}

void Insert_Begin(int x, Node*& head) {
    Node* NewNode = CreateNode(x);
    if (head == NULL) {
        head = NewNode;
        return;
    }
    head->prev = NewNode;
    NewNode->next = head;
    head = NewNode;
}