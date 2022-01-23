#include <iostream>

using namespace std;

bool funct(string** S, int n, int m, char* C, int c, float w) {
    for (int i = 0; i < n; i++) {
        int match = 0, somma = 0;
        for (int j = 0; j < m; j++) {
            match += S[i][j].length();
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < S[i][j].length(); l++) {
                    if (S[i][j][l] == C[k]) somma++;
                }
            }
        }
        if (static_cast<double>(match) / somma * 100 > w) return true;
    }

    // @TODO: Fare anche per le colonne

    return false;
}