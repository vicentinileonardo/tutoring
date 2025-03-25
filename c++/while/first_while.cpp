#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Inserisci un numero: ";
    cin >> N;

    int i = 1;
    while (i <= N) {
        cout << i << " ";
        i++;
    }
    cout << endl;

    return 0;
}
