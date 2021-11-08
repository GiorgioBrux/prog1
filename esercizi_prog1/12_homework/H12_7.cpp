/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iostream>

using namespace std;

int numero_consonanti(string calcolo) {
    unsigned int conta = 0;

    for (int i = 0; i < calcolo.length(); i++) {
        if (calcolo[i] != 'a' && calcolo[i] != 'e' && calcolo[i] != 'i' && calcolo[i] != 'o' && calcolo[i] != 'u') {
            conta++;
        }
    }

    return conta;
}

int main() {
    string nome, cognome;

    cout << "Inserisci il tuo nome e cognome: ";
    cin >> nome >> cognome;

    cout << "1. " << nome[0] << nome[nome.length() - 1] << cognome[1] << cognome[3] << endl;

    cout << "2. Caratteri presenti in tutti e due: ";

    // Attenzione: Se dei caratteri in comune sono presenti più volte nel nome,
    // verranno stampati più volte.
    for (int i = 0; i < nome.length(); i++) {
        for (int j = 0; j < cognome.length(); j++) {
            if (nome[i] == cognome[j]) {
                cout << nome[i];
                break;
            }
        }
    }

    cout << endl;

    if (nome[0] == cognome[cognome.length() - 1]) {
        cout << "Inoltre, la prima lettera del nome e l'ultima lettera del "
                "cognome sono uguali."
             << endl;
    }

    if (nome.length() == cognome.length()) {
        cout << "Inoltre, il nome e il cognome hanno la stessa lunghezza." << endl;
    }

    cout << "Consonanti nome: " << numero_consonanti(nome) << endl;
    cout << "Consonanti cognome: " << numero_consonanti(cognome) << endl;
}