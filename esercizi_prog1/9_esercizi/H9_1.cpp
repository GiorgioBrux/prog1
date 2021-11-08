/*
 * Author: giorgiobrux
 * Created Date: Friday November 5th 2021
 * -----
 * Last Modified:
 */

#include <iostream>

using namespace std;

// Prendere in input una matrice V n*n, e stampare la media dei valori
// differenza tra gli elementi deglla diagonale principale e quelli della
// diagonale secondaria.

// Rappresentazione grafica:
//
//    0  1  2
// 0  x     y
// 1    x/y
// 2  y     x
//
// x = diagonale primaria, y = diagonale secondaria
// per ogni X dobbiamo sottrarlo alla rispettiva y, e poi aggiungerlo alla somma
// per poi fare la media.

int main() {
    cout << "Inserisci le dimensioni della matrice V: ";
    int n;
    cin >> n;

    int V[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Inserisci elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> V[i][j];
        }
        cout << endl;
    }

    int sommadp = 0, sommads = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                sommadp += V[i][j];
            }
            if (i + j == (n - 1)) {
                sommads += V[i][j];
            }
        }
        cout << endl;
    }
    cout << "Sommadp: " << sommadp << ", Sommads: " << sommads << endl;
    cout << "Media: " << (double)(sommadp - sommads) / n << endl;
}