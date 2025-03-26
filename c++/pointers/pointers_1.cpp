/*
Basic Pointer Declaration and Dereferencing

Declare an integer variable, create a pointer to it,
and display both the value and address of the variable using the pointer.

This exercise introduces basic pointer syntax, including declaration, assignment, and dereferencing.

---

Dichiarazione di base del puntatore e dereferenziazione

Dichiarare una variabile intera, creare un puntatore ad essa,
e visualizzare sia il valore che l'indirizzo della variabile utilizzando il puntatore.

Questo esercizio introduce la sintassi di base del puntatore, inclusa la dichiarazione, l'assegnazione e la dereferenziazione.
*/

#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int* ptr = &num;  // Pointer stores the address of num

    cout << "Value of num: " << num << endl;
    cout << "Address of num: " << &num << endl;
    cout << "Value stored in pointer (address of num): " << ptr << endl;
    cout << "Value pointed by pointer: " << *ptr << endl;

    // address of pointer, just to show that it's different and not really useful in this case
    cout << "Address of pointer: " << &ptr << endl;

    return 0;
}
