#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 10;

int searchValue(int matrix[][SIZE], int value);

int main() {
    int matrix[SIZE][SIZE];
    int value;

    srand(time(0));

    // Inizializzazione della matrice
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Stampa della matrice
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Inserisci il valore da cercare: ";
    cin >> value;

    if (searchValue(matrix, value)) {
        cout << "Il valore " << value << " e' stato trovato." << endl;
    } else {
        cout << "Il valore " << value << " non e' stato trovato." << endl;
    }

    return 0;
}

int searchValue(int matrix[][SIZE], int value) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == value) {
                return 1;
            }
        }
    }

    return 0;
}
