#include <iostream>
using namespace std;

const int SIZE = 3;

void inputMatrix(int matrix[SIZE][SIZE]) {
    cout << "Inserisci i valori della matrice " << SIZE << "x" << SIZE << ":" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[SIZE][SIZE], const string& label) {
    cout << label << ":" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(const int input[SIZE][SIZE], int output[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            output[j][i] = input[i][j];
        }
    }
}

int main() {
    int matrix[SIZE][SIZE], transposed[SIZE][SIZE];
    
    inputMatrix(matrix);
    printMatrix(matrix, "Matrice");
    
    transposeMatrix(matrix, transposed);
    printMatrix(transposed, "Trasposta");
    
    return 0;
}
