/*
 Implement a Stack Using Pointers
*/

#include <iostream>
using namespace std;

class Stack {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* top;
public:
    Stack() : top(nullptr) {}

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!top) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        return top ? top->data : -1;
    }

    // print the stack
    void print() {
        Node* temp = top;
        cout << "Stack: ";
        if (!temp) {
            cout << "Empty" << endl;
            return;
        }
        cout << "Top -> ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (top) pop();
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    s.print();
    cout << "Current top: " << s.peek() << endl;
    
    s.pop();
    cout << "Top after pop: " << s.peek() << endl;

    s.print();

    s.push(15);
    s.push(20);
    s.print();

    return 0;
}
