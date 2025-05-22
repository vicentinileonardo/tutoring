#include <iostream>
#include <string>

using namespace std;

struct veicolo{
    string targa;
    string modello;
    int immatricolazione;
    int chilometri;
    int manutenzione;
};

void aggiungiVeicolo(veicolo vett[], int dim){
    for(int i=0; i<dim; i++){
        cout<<"Inserisci TARGA: ";
        cin>>vett[i].targa;
        cout<<"Inserisci MODELLO: ";
        cin>>vett[i].modello;
        cout<<"Inserisci ANNO di IMMATRICOLAZIONE: ";
        cin>>vett[i].immatricolazione;
        cout<<"Inserisci CHILOMETRAGGIO: ";
        cin>>vett[i].chilometri;
        cout<<"Veicolo in manutenzioone? (1-->si; 0-->no) ";
        cin>>vett[i].manutenzione;
        cout<<endl;
    }
}

void stampaAuto(veicolo vett[], int dim){
    for(int i=0; i<dim; i++){
        cout<<"Veicolo numero "<<i<<endl;
        cout<<"TARGA: "<<vett[i].targa<<endl;
        cout<<"MODELLO: "<<vett[i].modello<<endl;
        cout<<"ANNO di IMMATRICOLAZIONE: "<<vett[i].immatricolazione<<endl;
        cout<<"CHILOMETRAGGIO: "<<vett[i].chilometri<<endl;
        cout<<"MANUTENZIONE: "<<vett[i].manutenzione;
        cout<<endl;
    }
}

void veicoliVecchi(veicolo vett[], int dim, int anno){
    for(int i=0; i<dim; i++){
        if(vett[i].immatricolazione<anno){
            cout<<"Veicolo numero "<<i<<endl;
            cout<<"TARGA: "<<vett[i].targa<<endl;
            cout<<"MODELLO: "<<vett[i].modello<<endl;
            cout<<"ANNO di IMMATRICOLAZIONE: "<<vett[i].immatricolazione<<endl;
            cout<<"CHILOMETRAGGIO: "<<vett[i].chilometri<<endl;
            cout<<"MANUTENZIONE: "<<vett[i].manutenzione;
            cout<<endl;
        }
    }
}

void ordinaChilometraggio(veicolo vett[], int dim){
    // bubble sort per ordinare i veicoli in base al chilometraggio
    for (int i=0; i<dim; i++){
        for (int j=0; j<dim-1; j++){
            if (vett[j].chilometri < vett[j+1].chilometri){
                veicolo temp = vett[j];
                vett[j] = vett[j+1];
                vett[j+1] = temp;
            }
        }
    }
}

// Funzione 5: Stampa veicoli immatricolati prima di una certa data e in manutenzione
void stampaVeicoliVecchiInManutenzione(veicolo vett[], int dim, int anno){
    cout << "Veicoli immatricolati prima del " << anno << " e in manutenzione:" << endl;
    for(int i=0; i<dim; i++){
        if(vett[i].immatricolazione < anno && vett[i].manutenzione == 1){
            cout<<"Veicolo numero "<<i<<endl;
            cout<<"TARGA: "<<vett[i].targa<<endl;
            cout<<"MODELLO: "<<vett[i].modello<<endl;
            cout<<"ANNO di IMMATRICOLAZIONE: "<<vett[i].immatricolazione<<endl;
            cout<<"CHILOMETRAGGIO: "<<vett[i].chilometri<<endl;
            cout<<"MANUTENZIONE: "<<vett[i].manutenzione;
            cout<<endl;
        }
    }
}

// Funzione 6: Calcola la media dei Km percorsi dai veicoli immatricolati dopo il 2000
float mediaKmDopoAnno(veicolo vett[], int dim, int anno = 2000){
    int sommaKm = 0;
    int contaVeicoli = 0;
    
    for(int i=0; i<dim; i++){
        if(vett[i].immatricolazione > anno){
            sommaKm += vett[i].chilometri;
            contaVeicoli++;
        }
    }
    
    if(contaVeicoli > 0){
        return (float)sommaKm / contaVeicoli;
    } else {
        return 0; // Nessun veicolo trovato dopo l'anno specificato
    }
}

// Funzione 7: Modifica lo stato a "in manutenzione" dato in input la targa
void impostaManutenzione(veicolo vett[], int dim, string targa){
    bool trovato = false;
    
    for(int i=0; i<dim; i++){
        if(vett[i].targa == targa){
            vett[i].manutenzione = 1;
            cout << "Veicolo con targa " << targa << " impostato in manutenzione." << endl;
            trovato = true;
            break;
        }
    }
    
    if(!trovato){
        cout << "Veicolo con targa " << targa << " non trovato." << endl;
    }
}

int main()
{
    int dim;
    int scelta;
    string targa;
    int anno;
    
    // Menu iniziale per la dimensione della flotta
    cout << "===== GESTIONE FLOTTA VEICOLI =====" << endl;
    cout << "Inserisci la dimensione della flotta: ";
    cin >> dim;
    
    veicolo vett[dim];
    
    // Menu principale
    do {
        cout << "\n===== MENU PRINCIPALE =====" << endl;
        cout << "1. Aggiungi veicoli alla flotta" << endl;
        cout << "2. Visualizza tutti i veicoli" << endl;
        cout << "3. Visualizza veicoli vecchi (immatricolati prima di un certo anno)" << endl;
        cout << "4. Ordina veicoli per chilometraggio (decrescente)" << endl;
        cout << "5. Visualizza veicoli vecchi in manutenzione" << endl;
        cout << "6. Calcola media chilometri dei veicoli dopo il 2000" << endl;
        cout << "7. Imposta un veicolo in manutenzione" << endl;
        cout << "0. Esci" << endl;
        cout << "Scelta: ";
        cin >> scelta;
        
        switch(scelta) {
            case 1:
                aggiungiVeicolo(vett, dim);
                break;
                
            case 2:
                stampaAuto(vett, dim);
                break;
                
            case 3:
                cout << "Inserisci l'anno limite: ";
                cin >> anno;
                veicoliVecchi(vett, dim, anno);
                break;
                
            case 4:
                ordinaChilometraggio(vett, dim);
                cout << "Veicoli ordinati per chilometraggio in modo decrescente." << endl;
                stampaAuto(vett, dim);
                break;
                
            case 5:
                cout << "Inserisci l'anno limite: ";
                cin >> anno;
                stampaVeicoliVecchiInManutenzione(vett, dim, anno);
                break;
                
            case 6:
                cout << "Media chilometri dei veicoli immatricolati dopo il 2000: " 
                     << mediaKmDopoAnno(vett, dim) << " km" << endl;
                break;
                
            case 7:
                cout << "Inserisci la targa del veicolo da mettere in manutenzione: ";
                cin >> targa;
                impostaManutenzione(vett, dim, targa);
                break;
                
            case 0:
                cout << "Uscita dal programma..." << endl;
                break;
                
            default:
                cout << "Scelta non valida. Riprova." << endl;
        }
        
    } while(scelta != 0);
    
    return 0;
}