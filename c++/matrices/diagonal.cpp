#include <iostream>
using namespace std;

int main() {
    int matrix[3][3];
    int sommaDiagonale = 0;

    cout << "Inserisci i valori della matrice 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Riga " << i + 1 << ":" << endl;
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matrice:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        sommaDiagonale += matrix[i][i];
    }

    cout << "Somma della diagonale principale: " << sommaDiagonale << endl;

    return 0;
}
