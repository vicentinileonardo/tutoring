/*
Pointer to Pointer (Double Pointer)

Create a pointer to a pointer and print the value of a variable using both pointers.

Introduces double pointers (**ptr)

---

Doppio puntatore (Puntatore a puntatore)

Creare un puntatore a un puntatore e stampare il valore di una variabile utilizzando entrambi i puntatori.

Introduce i puntatori doppi (**ptr)
*/

#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int* ptr = &num;
    int** dptr = &ptr;

    cout << "Value of num: " << num << endl;
    cout << "Value through single pointer: " << *ptr << endl;
    cout << "Value through double pointer: " << **dptr << endl;

    cout << "--------------------------------" << endl;

    // address of num, ptr and dptr
    cout << "Address of num: " << &num << endl
         << "Address of ptr: " << &ptr << endl
         << "Address of dptr: " << &dptr << endl;

    cout << "--------------------------------" << endl;

    // print ptr and dptr
    cout << "Value of ptr: " << ptr <<  " (which is the address of num)" << endl
         << "Value of dptr: " << dptr << " (which is the address of ptr)" << endl;

    return 0;
}
