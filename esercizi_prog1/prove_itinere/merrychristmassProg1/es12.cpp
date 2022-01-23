#include <iostream>

using namespace std;

bool funct(string** A, int m, int n, short w) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (A[i][j].length() < w || A[i][j + 1].length() < w) continue;
            int f = 0;
            for (int k = 0; k < w; k++) {
                if (A[i][j][k] == A[i][j + 1][A[i][j + 1].length() - k - 1])
                    f++;
                else
                    break;
            }
            if (f == w) return true;
        }
    }
    return false;
}

int main() {  // Funzione main non richiesta, usata solo per verificare la funzione
    const int DIM = 2;
    string** A = new string*[DIM];
    for (int i = 0; i < 5; i++) {
        A[i] = new string[5];
    }

    A[0][0] = "diooid";
    A[0][1] = "diooid";
    A[1][0] = "abcdef";
    A[1][1] = "abcdef";

    cout << funct(A, 2, 2, 2) << endl;  // true

    A[0][1] = "abcdef";
    cout << funct(A, 2, 2, 2) << endl;  // false
}