#include <iostream>

using namespace std;

bool funct(int ***A, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = i; l < n; l++) {
                for (int k = j + 1; k < m; k++) {
                    if (*A[i][j] == *A[l][k]) return true;
                }
            }
        }
    }
    return false;
}

int main() {  // Test funzione
    int ***A = new int **[2];
    for (int i = 0; i < 2; i++) {
        A[i] = new int *[2];
        for (int j = 0; j < 2; j++) {
            A[i][j] = new int(0);
        }
    }
    *A[0][1] = 1;
    *A[0][0] = 1;
    *A[1][0] = 2;
    *A[1][1] = 3;

    // 1 1
    // 2 3
    cout << funct(A, 2, 2) << endl;  // 1

    *A[0][1] = 1;
    *A[0][0] = 2;
    *A[1][0] = 3;
    *A[1][1] = 4;

    // 1 2
    // 3 4
    cout << funct(A, 2, 2) << endl;  // 0
}