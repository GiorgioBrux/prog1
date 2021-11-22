#include <iostream>

using namespace std;

bool calcola(int **arr, int n, int m, double w) {
    // Calcolo somma diagonale secondaria
    int sommaDiagonaleSec = 0;
    for (int i = 0; i < n; i++) {
        sommaDiagonaleSec += arr[i][m - i - 1];
    }
    cout << "Somma elementi diagonale secondaria: " << sommaDiagonaleSec << endl;
    for (int i = 0; i < m; i++) {
        int conta = 0;
        for (int j = 0; j < n; j++) {
            conta += arr[j][i];
        }
        if (conta + sommaDiagonaleSec > w) return true;
    }
    return false;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
    int **matrice = new int *[2];
    for (int i = 0; i < 2; i++) {
        *(matrice + i) = new int[2];
    }

    matrice[0][0] = 1;
    matrice[0][1] = 2;
    matrice[1][0] = 3;
    matrice[1][1] = 4;

    // 1 2
    // 3 4
    cout << calcola(matrice, 2, 2, 10);
}