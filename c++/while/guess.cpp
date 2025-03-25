#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int number = rand() % 5 + 1;
    int guess;
    
    cout << "Indovina il numero (1-5): ";
    cin >> guess;
    
    while (guess != number) {
        cout << "Sbagliato! Riprova: ";
        cin >> guess;
    }
    
    cout << "Esatto! Il numero era " << number << endl;
    
    return 0;
}
