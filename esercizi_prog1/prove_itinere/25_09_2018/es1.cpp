#include <iostream>

using namespace std;

bool calcola(int*** A, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = (k == i ? j + 1 : 0); l < m; l++) {
                    if (*A[i][j] == *A[k][l]) return true;
                }
            }
        }
    }
    return false;
}