#include <iostream>
using namespace std;

int main() {
    int choice;
    do {
        cout << "============" << endl;
        cout << "Menu:" << endl;
        cout << "1. Somma" << endl;
        cout << "2. Sottrazione" << endl;
        cout << "3. Uscita" << endl;
        cout << "Scelta: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Hai scelto la somma" << endl;
                cout << "Inserisci primo numero: ";
                int a, b;
                cin >> a;
                cout << "Inserisci secondo numero: ";
                cin >> b;
                cout << "La somma e': " << a + b << endl;
                cout << "Fine somma" << endl;
                break;
            case 2:
                cout << "Hai scelto la sottrazione" << endl;
                cout << "Inserisci primo numero: ";
                cin >> a;
                cout << "Inserisci secondo numero: ";
                cin >> b;
                cout << "La sottrazione e': " << a - b << endl;
                cout << "Fine sottrazione" << endl;
                break;
            case 3:
                cout << "Arrivederci!" << endl;
                break;
            default:
                cout << "Scelta non valida" << endl;
        }
    } while (choice != 3);
    
    return 0;
}
