/*
Esercitazione pre compito

In un istituto scolastico ci sono 200 studenti vengono presi in esame 

Per la risoluzione del problema i seguenti dati:
- Classe frequentata (1,2,3,4,5);
- Sesso (m/f);
- Se lo studente si avvale o meno della religione cattolica (s/n)

Implementare un programma in linguaggio C++ che attraverso menu di scelta
e richiamo di funzioni permetta di:

1. Caricare gli array
2. Calcolare e visualizzare la percentuale di maschi del biennio che non si avvale della religione cattolica sul totale dei maschi
3. Calcolare e visualizzare quante sono le femmine del triennio che si avvalgono della religione cattolica
4. Quanti sono i maschi e le femmine di quarta

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_STUDENTI = 200;

void caricaDati(int classe[], char sesso[], char religione[], int &index);
void caricaDatiRandom(int classe[], char sesso[], char religione[], int &index);
double percentualeMaschiBiennioNoReligione(const int classe[], const char sesso[], const char religione[]);
int contaFemmineTriennioReligione(const int classe[], const char sesso[], const char religione[]);
void contaStudentiQuarta(const int classe[], const char sesso[], int &maschi, int &femmine);
void stampaTuttiGliStudenti(const int classe[], const char sesso[], const char religione[], int index);

int main() {

    // 3 array paralleli per i dati degli studenti
    int classe[NUM_STUDENTI];
    char sesso[NUM_STUDENTI];
    char religione[NUM_STUDENTI];

    // indice per tenere traccia di quanti studenti sono stati inseriti a mano
    int index = 0;
    int scelta;

    srand(time(0));

    do {
        cout << "=====================================\n";
        cout << "\nMenu:\n";
        cout << "1. Caricare un nuovo studente\n";
        cout << "2. Caricare tutti i dati in modo casuale\n";
        cout << "3. Percentuale maschi del biennio senza religione\n";
        cout << "4. Numero femmine del triennio con religione\n";
        cout << "5. Numero di maschi e femmine di quarta\n";
        cout << "6. Visualizza tutti gli studenti\n";
        cout << "7. Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1:
                caricaDati(classe, sesso, religione, index);
                break;
            case 2:
                caricaDatiRandom(classe, sesso, religione, index);
                cout << "Dati caricati casualmente (200 studenti).\n";
                break;
            case 3:
                cout << "Percentuale maschi del biennio senza religione: " 
                     << percentualeMaschiBiennioNoReligione(classe, sesso, religione) 
                     << "%\n";
                break;
            case 4:
                cout << "Numero di femmine del triennio che si avvalgono della religione: "
                     << contaFemmineTriennioReligione(classe, sesso, religione) 
                     << "\n";
                break;
            case 5: {
                int maschi, femmine;
                contaStudentiQuarta(classe, sesso, maschi, femmine);
                cout << "Maschi di quarta: " << maschi << "\n";
                cout << "Femmine di quarta: " << femmine << "\n";
                break;
            }
            case 6:
                stampaTuttiGliStudenti(classe, sesso, religione, index);
                break;
            case 7:
                cout << "Uscita dal programma.\n";
                break;
            default:
                cout << "Scelta non valida!\n";
        }
    } while (scelta != 7);

    return 0;
}

void caricaDati(int classe[], char sesso[], char religione[], int &index) {
    if (index >= NUM_STUDENTI) {
        cout << "Limite di studenti raggiunto!\n";
        return;
    }
    cout << "Inserisci i dati per lo studente " << index + 1 << "\n";
    do {
        cout << "Classe (1-5): ";
        cin >> classe[index];
    } while (classe[index] < 1 || classe[index] > 5);
    do {
        cout << "Sesso (m/f): ";
        cin >> sesso[index];
    } while (sesso[index] != 'm' && sesso[index] != 'f');
    do {
        cout << "Religione cattolica (s/n): ";
        cin >> religione[index];
    } while (religione[index] != 's' && religione[index] != 'n');
    index++;
}

void caricaDatiRandom(int classe[], char sesso[], char religione[], int &index) {
    index = 0;                                          // reset index, buttiamo via i dati vecchi e popoliamo da capo
    for (int i = 0; i < NUM_STUDENTI; i++) {
        classe[i] = rand() % 5 + 1;                     // 1-5, a caso
        sesso[i] = (rand() % 2 == 0) ? 'm' : 'f';       // 0 = maschio, 1 = femmina, a caso
        religione[i] = (rand() % 2 == 0) ? 's' : 'n';   // 0 = sì, 1 = no, a caso
    }
    index = NUM_STUDENTI;
}

double percentualeMaschiBiennioNoReligione(const int classe[], const char sesso[], const char religione[]) {
    int totaleMaschi = 0, maschiNoReligione = 0;
    for (int i = 0; i < NUM_STUDENTI; i++) {
        if (sesso[i] == 'm') {
            totaleMaschi++;
            if ((classe[i] == 1 || classe[i] == 2) && religione[i] == 'n') {
                maschiNoReligione++;
            }
        }
    }
    return (totaleMaschi > 0) ? (maschiNoReligione * 100.0 / totaleMaschi) : 0;
}

int contaFemmineTriennioReligione(const int classe[], const char sesso[], const char religione[]) {
    int count = 0;
    for (int i = 0; i < NUM_STUDENTI; i++) {
        if (sesso[i] == 'f' && (classe[i] >= 3 && classe[i] <= 5) && religione[i] == 's') {
            count++;
        }
    }
    return count;
}

void contaStudentiQuarta(const int classe[], const char sesso[], int &maschi, int &femmine) {
    maschi = femmine = 0;
    for (int i = 0; i < NUM_STUDENTI; i++) {
        if (classe[i] == 4) {
            if (sesso[i] == 'm') {
                maschi++;
            } else if (sesso[i] == 'f') {
                femmine++;
            }
        }
    }
}

void stampaTuttiGliStudenti(const int classe[], const char sesso[], const char religione[], int index) {
    if (index == 0) {
        cout << "Nessuno studente inserito.\n";
        return;
    }
    for (int i = 0; i < index; i++) {
        cout << "Studente " << i + 1 << ": ";
        cout << "Classe: " << classe[i] << ", ";
        cout << "Sesso: " << sesso[i] << ", ";
        cout << "Religione: " << religione[i] << endl;
    }
}