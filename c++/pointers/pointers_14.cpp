/*
Implement a Singly Linked List Using Pointers

Implement a linked list with insertion, removal, and display operations. ]
The linked list should be implemented using pointers.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false; // Not found
    }

    int searchIndex(int val) {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == val) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1; // Not found
    }

    void remove(int val) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp) {
            if (temp->data == val) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    cout << "----------------" << endl;

    list.remove(20);
    list.display();
    cout << "----------------" << endl;

    cout << "Search for 10, 20, 30" << endl;
    cout << list.search(10) << endl;
    cout << list.search(20) << endl;
    cout << list.search(30) << endl;
    cout << "----------------" << endl;

    cout << "Search Index for 10, 20, 30" << endl;
    cout << list.searchIndex(10) << endl;
    cout << list.searchIndex(20) << endl;
    cout << list.searchIndex(30) << endl;
    cout << "----------------" << endl;

    list.insert(70);
    list.insert(80);
    list.insert(90);
    list.display();
    cout << "----------------" << endl;

    cout << "Search Index for 10, 20, 30" << endl;
    cout << list.searchIndex(10) << endl;
    cout << list.searchIndex(20) << endl;
    cout << list.searchIndex(30) << endl;
    cout << "----------------" << endl;


    return 0;
}
