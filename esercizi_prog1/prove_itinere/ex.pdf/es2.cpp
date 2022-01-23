#include <iostream>

using namespace std;

bool palindroma(string str) {
    bool palindroma = true;
    for (int k = 0; k < str.length() / 2; k++) {
        if (str[k] != str[str.length() - k]) {
            palindroma = false;
            break;
        }
    }
    return palindroma;
}

bool funct(string*** M, int n, int m) {
    int righe[n];
    int colonne[m];
    for (int i = 0; i < n; i++) {
        int cont = 0;
        for (int j = 0; j < m; j++) {
            if (M[i][j] == nullptr) continue;
            if (palindroma(*M[i][j])) cont++;
        }
        righe[i] = cont;
    }
    for (int i = 0; i < m; i++) {
        int cont = 0;
        for (int j = 0; j < n; j++) {
            if (M[j][i] == nullptr) continue;
            if (palindroma(*M[j][i])) cont++;
        }
        colonne[i] = cont;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (righe[i] == colonne[j]) return true;
        }
    }

    return false;
}