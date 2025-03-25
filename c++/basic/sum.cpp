#include <iostream>
using namespace std;

int somma(int a, int b) {
    return a + b;
}

int main() {
    int a, b;
    cout << "Inserisci primo numero intero: ";
    cin >> a;
    cout << "Inserisci secondo numero intero: ";
    cin >> b;
    cout << "La somma dei due numeri è: " << somma(a, b) << endl;
    return 0;
}
