/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice di puntatori
ad interi di dimensioni n*m, due interi positivi a e b ed uno short s (si assuma a < b ed s < n).
Il metodo restituisca una copia della matrice in cui ogni numero di una singola colonna della
matrice di origine che risulti presente almeno s volte nella colonna stessia sia sostituito, nella
corrispondente colonna nella matrice copia, con un numero pseudo-casuale negativo appartenente
all'intervallo [-b, -a] (tranne gli elementi che risultano nullptr nella matrice originale!) */

#include <iostream>
using namespace std;

int*** funct(int*** A, int n, int m, int a, int b, short s) {
    int*** res = new int**[n];
    for (int i = 0; i < n; i++) res[i] = new int*[m];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (A[j][i] == NULL) continue;
            int var = *A[j][i];
            int conta = 0;
            for (int l = 0; l < n; l++) {
                if (A[l][i] == NULL) continue;
                if (*A[l][i] == var) conta++;
            }
            if (conta >= s) {
                int ra = rand() % (b - a + 1) + a;  // (max - min + 1) + min
                res[j][i] = new int(ra * -1);
            } else
                res[j][i] = new int(var);
        }
    return res;
}