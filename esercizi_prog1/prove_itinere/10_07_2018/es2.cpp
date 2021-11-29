#include <iostream>

using namespace std;

string** calcola(string** arr, int n, int m, int k) {
    string** copia = new string*[n];
    for (int i = 0; i < m; i++) {
        copia[i] = new string[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Stringa '" << arr[i][j] << "' length=" << arr[i][j].length() << endl;
            for (int k = 0; k < arr[i][j].length(); k++) {
                switch (arr[i][j][k]) {
                    case 'j':
                    case 'J':
                    case 'K':
                    case 'k':
                    case 'W':
                    case 'w':
                    case 'x':
                    case 'X':
                    case 'y':
                    case 'Y':
                        break;
                    default:
                        copia[i][j] += arr[i][j][k];
                }
            }
        }
    }
    cout << "Return..." << endl;
    return copia;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
    auto** matrice = new string*[2];
    for (int i = 0; i < 2; i++) {
        *(matrice + i) = new string[2];
    }

    matrice[0][0] = "jkjk";     // -> ""
    matrice[0][1] = "xkl";      // -> "l"
    matrice[1][0] = "kjwdd";    // -> "dd"
    matrice[1][1] = "ldawdjk";  // -> "ldad"

    string** arr = calcola(matrice, 2, 2, 1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) cout << arr[i][j] << endl;
    }
}
