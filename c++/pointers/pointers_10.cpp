/*
Pointer and Function Pointers

Use a function pointer to call different functions dynamically.

Shows how function pointers work.

---

Puntatore e Puntatori a Funzioni

Utilizzare un puntatore a funzione per chiamare diverse funzioni dinamicamente.

Mostra come funzionano i puntatori a funzione.
*/

#include <iostream>
using namespace std;

void greet() {
    cout << "Hello, World!" << endl;
}

void farewell() {
    cout << "Goodbye, World!" << endl;
}

int main() {
    void (*funcPtr)(); // Declare function pointer
    funcPtr = greet;
    funcPtr(); // Call greet

    funcPtr = farewell;
    funcPtr(); // Call farewell

    return 0;
}
