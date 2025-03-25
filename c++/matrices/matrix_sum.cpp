#include <iostream>
using namespace std;

void sommaMatrici(int m1[3][3], int m2[3][3], int risultato[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            risultato[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

int main() {
    int matrix1[3][3];
    int matrix2[3][3];
    int risultato[3][3];

    cout << "Inserisci i valori della prima matrice 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Riga " << i + 1 << ":" << endl;
        for (int j = 0; j < 3; j++) {
            cin >> matrix1[i][j];
        }
    }

    cout << "Inserisci i valori della seconda matrice 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Riga " << i + 1 << ":" << endl;
        for (int j = 0; j < 3; j++) {
            cin >> matrix2[i][j];
        }
    }

    sommaMatrici(matrix1, matrix2, risultato);

    cout << "Matrice risultante:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << risultato[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
