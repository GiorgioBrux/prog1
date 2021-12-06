#include <iostream>

using namespace std;

bool calcola(int **A, int n, double w) {
    int sommadiag = 0;
    for (int i = 0; i < n; i++) {
        sommadiag += A[i][n - i - 1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        }
    }
}