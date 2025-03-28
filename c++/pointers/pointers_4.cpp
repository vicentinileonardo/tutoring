/*
Swapping Two Numbers Using Pointers

Write a function to swap two numbers using pointers.

Illustrates how to pass pointers to functions and modify variables.

---

Invertire due numeri utilizzando i puntatori

Scrivere una funzione per scambiare due numeri utilizzando i puntatori.

Illustra come passare i puntatori alle funzioni e modificare le variabili.
*/

#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "Before Swap: x=" << x << ", y=" << y << endl;
    
    swap(&x, &y);
    
    cout << "After Swap: x=" << x << ", y=" << y << endl;
    return 0;
}
