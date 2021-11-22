#include <iostream>

using namespace std;

int calcolo(long int **arr, int n, int m, long int x) {
    int nOcc = 0;
    int nOccInd = 0;
    for (int i = 0; i < m; i++) {
        int nOccLoc = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == x) nOccLoc++;
        }
        if (nOccLoc > nOcc) {
            nOcc = nOccLoc;
            nOccInd = i;
        }
    }
    return nOccInd;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
    long int **matrice = new long int *[2];
    for (int i = 0; i < 2; i++) {
        *(matrice + i) = new long int[2];
    }

    matrice[0][0] = 1;
    matrice[0][1] = 2;
    matrice[1][0] = 1;
    matrice[1][1] = 4;

    // 1 2
    // 1 4
    cout << calcolo(matrice, 2, 2, 1) << endl;  // Output: 0

    matrice[0][0] = 2;
    matrice[0][1] = 2;
    matrice[1][0] = 3;
    matrice[1][1] = 2;

    // 2 2
    // 3 2

    cout << calcolo(matrice, 2, 2, 2) << endl;  // Output: 1
}