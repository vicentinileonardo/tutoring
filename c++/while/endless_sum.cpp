#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int number;
    
    do {
        cout << "Inserisci un numero: ";
        cin >> number;
        sum += number;
        cout << "Somma attuale: " << sum << endl;
    } while (number != 0);
    
    cout << "Somma finale: " << sum << endl;
    
    return 0;
}
