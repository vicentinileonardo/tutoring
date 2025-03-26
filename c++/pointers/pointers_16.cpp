/*
Implement a Circular Linked List
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
    Node* tail;
public:
    CircularLinkedList() : tail(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        if (!tail) return;
        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to head)" << endl;
    }

    ~CircularLinkedList() {
        if (!tail) return;
        Node* temp = tail->next;
        Node* next;
        while (temp != tail) {
            next = temp->next;
            delete temp;
            temp = next;
        }
        delete tail;
    }
};

int main() {
    CircularLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.display();
    return 0;
}
