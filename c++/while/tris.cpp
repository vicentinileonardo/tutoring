#include <iostream>
using namespace std;

const int SIZE = 3;
const char EMPTY = ' ';

// stampa griglia con delimitatori
void stampa_griglia(char griglia[SIZE][SIZE]) {
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << " " << griglia[i][j] << " ";
            if (j < SIZE - 1) cout << "|";          // delimitatore colonna, tranne per l'ultima colonna
        }
        cout << endl;
        if (i < SIZE - 1) cout << "---+---+---\n";  // delimitatore riga, tranne per l'ultima riga
    }
    cout << "\n";
}

// controlla se c'è un vincitore: prima controlla righe, poi colonne, poi diagonali
char calcola_vincitore(char griglia[SIZE][SIZE]) {

    for (int i = 0; i < SIZE; i++) {
        
        // controllo righe
        if ((griglia[i][0] == griglia[i][1] && griglia[i][1] == griglia[i][2]) && (griglia[i][0] == 'X' || griglia[i][0] == 'O')) {
            return griglia[i][0];
        }
        
        // controllo colonne
        if ((griglia[0][i] == griglia[1][i] && griglia[1][i] == griglia[2][i]) && (griglia[0][i] == 'X' || griglia[0][i] == 'O')) {
            return griglia[0][i];
        }
    }

    // Controllo diagonale 1 (da sinistra in alto a destra in basso)
    if ((griglia[0][0] == griglia[1][1] && griglia[1][1] == griglia[2][2]) &&
        (griglia[0][0] == 'X' || griglia[0][0] == 'O')) {
        return griglia[0][0];
    }
    // Controllo diagonale 2 (da destra in alto a sinistra in basso)
    if ((griglia[0][2] == griglia[1][1] && griglia[1][1] == griglia[2][0]) &&
        (griglia[0][2] == 'X' || griglia[0][2] == 'O')) {
        return griglia[0][2];
    }

    return ' '; // Nessun vincitore trovato in questa chiamata di funzione
}

// controlla se la griglia è piena
bool griglia_piena(char griglia[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (griglia[i][j] == EMPTY) return false;
        }
    }
    return true;
}

int main() {
    char vincitore = ' ';       // settato a ' ' per indicare nessun vincitore, inizialmente
    char turno = 'O';           // 'O' inizia per primo
    char griglia[SIZE][SIZE];   

    // inizializza la griglia con EMPTY character settato inizialmente (char ' ' oppure '$')
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            griglia[r][c] = EMPTY;
        }
    }

    // loop di gioco
    // condizioni per entrare nel loop: ancora nessun vincitore e la griglia non è piena
    while (vincitore == ' ' && !griglia_piena(griglia)) {

        // 1) stampa la griglia
        stampa_griglia(griglia);

        int ri, ci;
        bool valid_move = false;

        // 2) chiedi mossa e controlla che la mossa sia valida, altrimenti ripeto
        while (!valid_move) {
            cout << "Turno di " << turno << endl;
            cout << "Scegli riga (0-2): ";
            cin >> ri;
            cout << "Scegli colonna (0-2): ";
            cin >> ci;

            if (ri >= 0 && ri < SIZE && ci >= 0 && ci < SIZE && griglia[ri][ci] == EMPTY) {
                griglia[ri][ci] = turno;
                valid_move = true;
            } else {
                cout << "Mossa non valida. Riprova.\n";
            }
        }

        // 3) Controlla se c'è un vincitore
        vincitore = calcola_vincitore(griglia);

        // 4) Cambia turno (operatore ternario)
        turno = (turno == 'O') ? 'X' : 'O';
    }

    // Stampa la griglia finale, siamo usciti dal loop quindi c'è un vincitore o la griglia è piena (pareggio)
    stampa_griglia(griglia);

    if (vincitore != ' ') {                                 // se vincitore diverso da ' ' allora c'è un vincitore
        cout << "Il vincitore è: " << vincitore << "!\n";
    } else {
        cout << "Pareggio! Nessun vincitore.\n";
    }

    return 0;
}
