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


void multiplyMatrix(const int matrix1[SIZE][SIZE], const int matrix2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], product[SIZE][SIZE];
    
    inputMatrix(matrix1);
    inputMatrix(matrix2);
    
    printMatrix(matrix1, "Matrice 1");
    printMatrix(matrix2, "Matrice 2");
    
    multiplyMatrix(matrix1, matrix2, product);
    printMatrix(product, "Prodotto");
    
    return 0;
}
