#include <iostream>

using namespace std;

double** calcola(double** A, int m, int n) {
    srand(time(NULL));
    double** ret = new double*[n];
    for (int i = 0; i < n; i++) {
        ret[i] = new double[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rand() % 2 > A[j][i])
                ret[i][j] = A[j][i];
            else
                ret[i][j] = A[i % m][j % n];
        }
    }

    return ret;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
    double** arr = new double*[2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new double[2];
    }
    arr[0][0] = 2;
    arr[0][1] = 0.5;

    arr[1][0] = 3.133413;
    arr[1][1] = 666.666;

    double** res = calcola(arr, 2, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    /**
     *
     * Input:
     *
     * 2         0.5
     * 3.13...   666.666
     *
     *
     *
     * Possibili output:
     *
     * 1)
     * 2       0.5
     * 0.5     666.666
     *
     * 2)
     * 2       0.5
     * 3.13..  666.66
     *
     * Questo perchè in base al random, l'elemento del nostro array arr[0][1] farà mettere alla
     * nel risultato[1][0] o arr[0][1] oppure arr[1%2][0%2], ovvero arr[1][0];
     *
     *
     *
     *
     **/
}