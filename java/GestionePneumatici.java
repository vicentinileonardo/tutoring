import java.util.Scanner;

// Classe Ruota
class Ruota {
    private double pressione; // Pressione in bar
    
    // Costruttore
    public Ruota(double pressione) {
        this.pressione = pressione;
    }
    
    // Metodo per ottenere la pressione
    public double getPressione() {
        return pressione;
    }
    
    // Metodo per impostare la pressione
    public void setPressione(double pressione) {
        this.pressione = pressione;
    }
}

// Classe Automobile
class Automobile {
    private String proprietario;
    private int telaio;
    private Ruota ruota1;
    private Ruota ruota2;
    private Ruota ruota3;
    private Ruota ruota4;
    
    // Costruttore che accetta 4 oggetti Ruota
    public Automobile(String proprietario, int telaio, Ruota r1, Ruota r2, Ruota r3, Ruota r4) {
        this.proprietario = proprietario;
        this.telaio = telaio;
        this.ruota1 = r1;
        this.ruota2 = r2;
        this.ruota3 = r3;
        this.ruota4 = r4;
    }

    // Metodi setter non necessari in questo contesto
    
    // Metodi getter
    public String getProprietario() {
        return proprietario;
    }
    
    public int getTelaio() {
        return telaio;
    }
    
    public Ruota getRuota1() {
        return ruota1;
    }
    
    public Ruota getRuota2() {
        return ruota2;
    }
    
    public Ruota getRuota3() {
        return ruota3;
    }
    
    public Ruota getRuota4() {
        return ruota4;
    }
    
    // Metodo per stampare tutte le informazioni dell'automobile
    public void stampaInformazioni() {
        System.out.println("\n=== INFORMAZIONI AUTOMOBILE ===");
        System.out.println("Proprietario: " + proprietario);
        System.out.println("Numero telaio: " + telaio);
        System.out.println("Pressione ruota 1: " + ruota1.getPressione() + " bar");
        System.out.println("Pressione ruota 2: " + ruota2.getPressione() + " bar");
        System.out.println("Pressione ruota 3: " + ruota3.getPressione() + " bar");
        System.out.println("Pressione ruota 4: " + ruota4.getPressione() + " bar");
    }
    
    // Metodo per sgonfiare una ruota
    public void sgonfiaRuota(int numeroRuota, double diminuzione) {
        switch(numeroRuota) {
            case 1:
                ruota1.setPressione(ruota1.getPressione() - diminuzione);
                break;
            case 2:
                ruota2.setPressione(ruota2.getPressione() - diminuzione);
                break;
            case 3:
                ruota3.setPressione(ruota3.getPressione() - diminuzione);
                break;
            case 4:
                ruota4.setPressione(ruota4.getPressione() - diminuzione);
                break;
        }
    }
}

// Classe principale
public class GestionePneumatici {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Acquisizione dati dal utente
        System.out.println("=== GESTIONE PNEUMATICI AUTOMOBILE ===\n");
        
        System.out.print("Inserisci il nome del proprietario: ");
        String proprietario = scanner.nextLine();
        
        System.out.print("Inserisci il numero di telaio: ");
        int telaio = scanner.nextInt();
        
        // Acquisizione pressioni delle quattro ruote
        System.out.print("Inserisci la pressione della ruota 1 (in bar): ");
        double pressione1 = scanner.nextDouble();
        
        System.out.print("Inserisci la pressione della ruota 2 (in bar): ");
        double pressione2 = scanner.nextDouble();
        
        System.out.print("Inserisci la pressione della ruota 3 (in bar): ");
        double pressione3 = scanner.nextDouble();
        
        System.out.print("Inserisci la pressione della ruota 4 (in bar): ");
        double pressione4 = scanner.nextDouble();
        
        // Creazione oggetti Ruota
        Ruota ruota1 = new Ruota(pressione1);
        Ruota ruota2 = new Ruota(pressione2);
        Ruota ruota3 = new Ruota(pressione3);
        Ruota ruota4 = new Ruota(pressione4);
        
        // Creazione oggetto Automobile
        Automobile auto = new Automobile(proprietario, telaio, ruota1, ruota2, ruota3, ruota4);
        
        // Stampa informazioni iniziali
        auto.stampaInformazioni();
        
        // Simulazione sgonfiaggio di una ruota
        System.out.println("\n=== SIMULAZIONE SGONFIAGGIO ===");
        System.out.println("Sgonfiaggio della ruota 1 di 0.5 bar...");
        auto.sgonfiaRuota(1, 0.5);
        
        // Stampa informazioni aggiornate
        System.out.println("\nInformazioni aggiornate dopo lo sgonfiaggio:");
        auto.stampaInformazioni();
        
        scanner.close();
    }
}