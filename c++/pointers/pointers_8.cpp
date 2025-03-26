/*
Function Returning a Pointer

Write a function that returns a pointer to an integer.

Demonstrates returning pointers from functions.

---

Funzione che restituisce un puntatore

Scrivere una funzione che restituisce un puntatore a un intero.

Dimostra il ritorno di puntatori dalle funzioni.
*/

#include <iostream>
using namespace std;

int* getPointer() {
    int* ptr = new int(42);
    return ptr;
}

int main() {
    int* ptr = getPointer();
    cout << "Value from function: " << *ptr << endl;

    // print ptr and address of ptr
    cout << "Value of ptr: " << ptr << " (which is the address of the integer variable)" << endl
         << "Address of ptr: " << &ptr << endl;

    delete ptr; 
    return 0;
}
