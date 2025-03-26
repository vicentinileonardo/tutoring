/*
Modifying Values Through Pointers

Create an integer variable and modify its value using a pointer.

This shows how pointers can modify variables directly.

---

Modifica dei valori attraverso i puntatori

Creare una variabile intera e modificarne il valore utilizzando un puntatore.

Questo mostra come i puntatori possano modificare direttamente le variabili.
*/

#include <iostream>
using namespace std;

int main() {
    int num = 20;
    int* ptr = &num;

    cout << "Before modification: " << num << endl;
    *ptr = 50; // Modify value using pointer
    cout << "After modification: " << num << endl;

    return 0;
}
