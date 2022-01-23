#include <iostream>

using namespace std;

int funct(string*** S, int n, int m, short* B) {
    int c_max = 0, c_ind = 0;

    for (int i = 0; i < n; i++) {
        int conta = 0;
        for (int j = 0; j < m; j++) {
            if (S[i][j] && S[i][j]->length() <= B[j]) conta++;
        }
        if (c_max < conta) {
            c_max = conta;
            c_ind = i;
        }
    }
    return c_ind;
}