#include <iostream>

using namespace std;

bool calcola(string **A, int n, int m, unsigned short k, unsigned short s) {
    for (int i = 0; i < n; i++) {
        int conta = 0;
        for (int j = 0; j < m; j++) {
            int min = 0;
            for (int k = 0; k < A[i][j].length(); k++) {
                if (A[i][j][k] >= 'a' && A[i][j][k] <= 'z') min++;
            }
            if (min < s) conta++;
        }
        if (conta > k) return true;
    }

    return false;
}