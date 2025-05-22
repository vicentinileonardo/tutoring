/*
Gestione di un Negozio

Descrizione:
Un negozio vende fino a 100 prodotti diversi. 
Ogni prodotto ha un codice numerico, un nome e un prezzo unitario. 

Il programma deve:

- Permettere l'inserimento di nuovi prodotti manualmente.
- Permettere l'inserimento di nuovi prodotti in modo automatico.
- Visualizzare l'elenco dei prodotti.
- Calcolare il valore totale dell'inventario.
- Trovare il prodotto più costoso.
- Trovare il prodotto meno costoso.
- Trovare il prodotto con il prezzo più vicino a quello inserito dall'utente.
- Trovare media dei prezzi dei prodotti.

*/

#include <iostream>
#include <string>
#include <iomanip> // setw()
#include <cstdlib>
#include <ctime>

using namespace std;

struct Prodotto {
    int codice;
    string nome;
    double prezzo;
};

void inserisciProdotto(Prodotto prodotti[], int &n) {
    if (n < 100) {
        cout << "Inserisci il codice del prodotto: ";
        cin >> prodotti[n].codice;
        cout << "Inserisci il nome del prodotto: ";
        cin >> prodotti[n].nome;
        cout << "Inserisci il prezzo del prodotto: ";
        cin >> prodotti[n].prezzo;
        n++;
    } else {
        cout << "Non è possibile inserire altri prodotti." << endl;
    }
}

void inserisciProdottoAutomatico(Prodotto prodotti[], int &n) {
    if (n < 100) {
        prodotti[n].codice = n + 1;
        prodotti[n].nome = "Prodotto " + to_string(n + 1);
        prodotti[n].prezzo = rand() % 1000 + 1;
        n++;
    } else {
        cout << "Non è possibile inserire altri prodotti." << endl;
    }
}

void inserisciTuttoAutomatico(Prodotto prodotti[], int &n) {
    for (int i = 0; i < 100; i++) {
        prodotti[i].codice = i + 1;
        prodotti[i].nome = "Prodotto " + to_string(i + 1);
        prodotti[i].prezzo = rand() % 1000 + 1;
        n++;
    }
}

void visualizzaProdotti(Prodotto prodotti[], int n) {
    cout << "Elenco dei prodotti:" << endl;
    cout << setw(5) << "Codice" << setw(20) << "Nome" << setw(10) << "Prezzo" << endl; // setw() imposta la larghezza del campo
    for (int i = 0; i < n; i++) {
        cout << setw(5) << prodotti[i].codice << setw(20) << prodotti[i].nome << setw(10) << prodotti[i].prezzo << endl;
    }
}

double valoreTotaleInventario(Prodotto prodotti[], int n) {
    double valore = 0;
    for (int i = 0; i < n; i++) {
        valore += prodotti[i].prezzo;
    }
    return valore;
}

Prodotto prodottoPiuCostoso(Prodotto prodotti[], int n) {
    Prodotto prodotto = prodotti[0];
    for (int i = 1; i < n; i++) {
        if (prodotti[i].prezzo > prodotto.prezzo) {
            prodotto = prodotti[i];
        }
    }
    return prodotto;
}

Prodotto prodottoMenoCostoso(Prodotto prodotti[], int n) {
    Prodotto prodotto = prodotti[0];
    for (int i = 1; i < n; i++) {
        if (prodotti[i].prezzo < prodotto.prezzo) {
            prodotto = prodotti[i];
        }
    }
    return prodotto;
}

Prodotto prodottoPrezzoVicino(Prodotto prodotti[], int n, double prezzo) {
    Prodotto prodotto = prodotti[0];
    double differenza = abs(prodotti[0].prezzo - prezzo);
    for (int i = 1; i < n; i++) {
        if (abs(prodotti[i].prezzo - prezzo) < differenza) {
            prodotto = prodotti[i];
            differenza = abs(prodotti[i].prezzo - prezzo);
        }
    }
    return prodotto;
}

double mediaPrezzi(Prodotto prodotti[], int n) {
    double media = 0;
    for (int i = 0; i < n; i++) {
        media += prodotti[i].prezzo;
    }
    return media / n;
}

int main() {

    srand(time(0));

    Prodotto prodotti[100];
    int n = 0; // Numero di prodotti caricati
    int scelta;
    double prezzo;

    Prodotto prodottoCostoso;
    Prodotto prodottoMenoCostosoVar;
    Prodotto prodottoVicino;

    do {
        cout << "Menu:" << endl;
        cout << "1) Inserisci prodotto" << endl;
        cout << "2) Inserisci prodotto automatico" << endl;
        cout << "3) Visualizza prodotti" << endl;
        cout << "4) Valore totale inventario" << endl;
        cout << "5) Prodotto più costoso" << endl;
        cout << "6) Prodotto meno costoso" << endl;
        cout << "7) Prodotto prezzo vicino" << endl;
        cout << "8) Media prezzi" << endl;
        cout << "9) Inserisci tutto automatico" << endl;
        cout << "0) Esci" << endl;
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1:
                inserisciProdotto(prodotti, n);
                break;
            case 2:
                inserisciProdottoAutomatico(prodotti, n);
                break;
            case 3:
                visualizzaProdotti(prodotti, n);
                break;
            case 4:
                cout << "Valore totale inventario: " << valoreTotaleInventario(prodotti, n) << endl;
                break;
            case 5:
                cout << "Prodotto più costoso:" << endl;
                prodottoCostoso = prodottoPiuCostoso(prodotti, n);
                cout << "Codice: " << prodottoCostoso.codice << endl;
                cout << "Nome: " << prodottoCostoso.nome << endl;
                cout << "Prezzo: " << prodottoCostoso.prezzo << endl;
                break;
            case 6:
                cout << "Prodotto meno costoso:" << endl;
                prodottoMenoCostosoVar = prodottoMenoCostoso(prodotti, n);
                cout << "Codice: " << prodottoMenoCostosoVar.codice << endl;
                cout << "Nome: " << prodottoMenoCostosoVar.nome << endl;
                cout << "Prezzo: " << prodottoMenoCostosoVar.prezzo << endl;
                break;
            case 7:
                cout << "Inserisci un prezzo: ";
                cin >> prezzo;
                cout << "Prodotto prezzo vicino:" << endl;
                prodottoVicino = prodottoPrezzoVicino(prodotti, n, prezzo);
                cout << "Codice: " << prodottoVicino.codice << endl;
                cout << "Nome: " << prodottoVicino.nome << endl;
                cout << "Prezzo: " << prodottoVicino.prezzo << endl;
                break;
            case 8:
                cout << "Media prezzi: " << mediaPrezzi(prodotti, n) << endl;
                break;
            case 9:
                inserisciTuttoAutomatico(prodotti, n);
                break;
            case 0:
                cout << "Uscita..." << endl;
                break;
            default:
                cout << "Scelta non valida." << endl;
        }
    } while (scelta != 0);

    return 0;
}
