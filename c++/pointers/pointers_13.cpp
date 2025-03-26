/*
Implement a Dynamic Array Using Pointers

Create a dynamic array using pointers and allow users to add elements.

Use new to allocate memory.
Resize array dynamically.
*/

#include <iostream>
using namespace std;

class DynamicArray {
    int* arr;
    int size;

public:
    DynamicArray(int s) : size(s) {
        arr = new int[size];
    }

    void setValue(int index, int value) {
        if (index >= 0 && index < size) { // check if index is valid, in range
            *(arr + index) = value;
        }
    }

    int getValue(int index) {
        return *(arr + index);
    }

    // print entire array
    void print() {
        for (int i = 0; i < size; i++) {
            cout << *(arr + i) << " ";
        }
        cout << endl;
    }

    void resize(int newSize) {
        int* newArr = new int[newSize];
        for (int i = 0; i < size; i++) {
            *(newArr + i) = *(arr + i);
        }
        // the rest of the elements of the new array will be 0s

        delete[] arr;
        arr = newArr;
        size = newSize;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray arr(5);
    arr.setValue(0, 10);
    arr.setValue(1, 20);
    cout << "Value at index 1: " << arr.getValue(1) << endl;
    arr.print();

    arr.resize(10);
    arr.setValue(5, 50);
    arr.setValue(6, 60);
    arr.print();

    arr.resize(3);
    arr.print();

    // Destructor will be called automatically

    return 0;
}
