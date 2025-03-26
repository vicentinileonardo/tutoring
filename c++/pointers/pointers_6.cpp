/*
Array Dynamic Allocation

Dynamically allocate an array, store values in it, and print them.

Shows how to allocate arrays dynamically and access elements.

---

Allocazione dinamica di un array

Alloca dinamicamente un array, memorizza dei valori al suo interno e li stampa.

Mostra come allocare dinamicamente degli array e accedere ai loro elementi.
*/

#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int* arr = new int[size]; // Dynamic allocation

    for (int i = 0; i < size; i++) {
        arr[i] = i * 10; 
    }

    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    delete[] arr; // Free memory
    return 0;
}
