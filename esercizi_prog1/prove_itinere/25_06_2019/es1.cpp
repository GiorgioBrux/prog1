#include <iostream>

using namespace std;

bool calcola(int **arr, int n, int m, short k, double x) {
    for (int i = 0; i < m; i++) {
        int coppie = 0;
        for (int j = 1; j < n; j++) {
            if ((double)arr[j - 1][i] / arr[j][i] < x) coppie++;
            if (coppie >= k) return true;
        }
    }
    return false;
}

int main()  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
{
    int **arr = new int *[2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new int[2];
    }
    arr[0][0] = 10;
    arr[0][1] = 10;
    arr[1][0] = 5;
    arr[1][1] = 1;
    cout << calcola(arr, 2, 2, 1, 5);
}