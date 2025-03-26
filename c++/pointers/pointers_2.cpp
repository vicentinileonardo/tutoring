/*
Pointer Arithmetic

Create an integer array 
and use a pointer to iterate through the array, printing its elements.

This demonstrates pointer arithmetic (ptr + i) and how pointers interact with arrays.

---

Aritmetica dei puntatori

Creare un array di interi
e utilizzare un puntatore per scorrere l'array, stampando i suoi elementi.

Questo dimostra l'aritmetica dei puntatori (ptr + i) e come i puntatori interagiscono con gli array.
*/

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int* ptr = arr;                 // Array name is a always a pointer to the first element of the array

    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": " << *(ptr + i) << endl;
        cout << "Element " << i << ": " << ptr[i] << endl;  // Equivalent to the above line

        // address of pointer as it iterates through the array
        cout << "Address of pointer: " << ptr + i << endl;
    }

    return 0;
}
