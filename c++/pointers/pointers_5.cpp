/*
Dynamic Memory Allocation

Dynamically allocate memory for an integer, assign it a value, and then free the memory.

Demonstrates `new` and `delete` for dynamic memory management.
*/

#include <iostream>
using namespace std;

int main() {
    int* ptr = new int; // Dynamically allocate memory (on the heap) for an integer
    *ptr = 100; 

    cout << "Dynamically allocated value: " << *ptr << endl;
    
    delete ptr; // Free memory
    return 0;
}
