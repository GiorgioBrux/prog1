#include <iostream>

using namespace std;

string* calcola(string** arr, int n, int m, int k) {
    string* copia = new string[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i][k].length(); j++) {
            switch (arr[i][k][j]) {
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
                    copia[i] += arr[i][k][j];
            }
        }
    }
    return copia;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
    auto** matrice = new string*[2];
    for (int i = 0; i < 2; i++) {
        *(matrice + i) = new string[2];
    }

    matrice[0][0] = "jkjk";
    matrice[0][1] = "xkl";
    matrice[1][0] = "kjwdd";
    matrice[1][1] = "ldawdjk";

    string* arr = calcola(matrice, 2, 2, 1);
    for (int i = 0; i < 2; i++) {
        cout << arr[i] << endl;
    }
}
