#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Inserisci un numero positivo: ";
    cin >> numero;

    while (numero <= 0) {  // Se l'utente sbaglia continua a chiedere il numero
        cout << "Errore! Inserisci un numero positivo: ";
        cin >> numero;
    }

    cout << "Numero valido: " << numero << endl;
    return 0;
}
