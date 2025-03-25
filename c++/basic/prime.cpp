#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Inserisci un numero intero: ";
    cin >> n;
    if (is_prime(n)) {
        cout << "Il numero è primo." << endl;
    } else {
        cout << "Il numero non è primo." << endl;
    }
    return 0;
}
