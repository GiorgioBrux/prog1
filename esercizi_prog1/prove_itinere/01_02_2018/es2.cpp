#include <iostream>

using namespace std;

bool stringhe(string*** matrice, int n, int m) {
    for (int i = 0; i < m; i++) {
        int risultati[n];
        for (int j = 0; j < n; j++) {
            int conta = 0;
            cout << "Provo coordinate " << j << ", " << i << endl;
            if (matrice[j][i] == nullptr) {
                conta = -1;
            } else {
                string s = *matrice[j][i];
                for (int k = 0; k < s.length(); k++) {
                    switch (s[k]) {
                        case 'A':
                        case 'a':
                        case 'E':
                        case 'e':
                        case 'i':
                        case 'I':
                        case 'O':
                        case 'o':
                        case 'U':
                        case 'u':
                            conta++;
                            break;
                    }
                }
                risultati[j] = conta;
                cout << "Stringa " << s << " ha " << conta << " vocali" << endl;
            }
        }
        // Compara array
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (risultati[j] != -1 && risultati[j] == risultati[k]) return true;
            }
        }
    }
    return false;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
    auto*** matrice = new string**[2];
    for (int i = 0; i < 5; i++) {
        *(matrice + i) = new string*[2];
        for (int j = 0; j < 5; j++) {
            matrice[i][j] = new string;
        }
    }

    *matrice[0][0] = "aabbbbb";
    *matrice[1][0] = "aaabbbb";
    *matrice[0][1] = "aaabbbb";
    *matrice[1][1] = "abbbbbb";
    cout << stringhe(matrice, 2, 2) << endl << "Esco...";
}