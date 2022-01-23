/**
 *  Scrivere un metodo che prenda in input un parametro formale
 *  matrice M di dimensioni n×m di puntatori a stringhe, e che
 *  restituisca true se esiste almeno una colonna in M che abbia
 *  un egual numero di stringhe palindrome di una riga di M
 **/

#include <iostream>
using namespace std;

bool calcola(string*** M, int n, int m) {
    int righe[n];
    int colonne[m];

    for (int i = 0; i < n; i++) {
        int conta = 0;
        for (int j = 0; j < m; j++) {
            string old = *M[i][j];
            reverse(M[i][j]->begin(), M[i][j]->end());
            if (*M[i][j] == old) conta++;
        }
        righe[i] = conta;
    }

    for (int i = 0; i < m; i++) {
        int conta = 0;
        for (int j = 0; j < n; j++) {
            string old = *M[j][i];
            reverse(M[j][i]->begin(), M[j][i]->end());
            if (*M[j][i] == old) conta++;
        }
        colonne[i] = conta;
    }

    // Confronta array

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (righe[i] == colonne[j]) return true;
        }
    }

    return false;
}

int main() {
    string*** s = new string**[3];
    for (int i = 0; i < 3; i++) {
        s[i] = new string*[3];
    }

    s[0][0] = new string("abcbc");
    s[0][1] = new string("abcdefg");
    s[0][2] = new string("abcdefg");
    s[1][0] = new string("abcdefg");
    s[1][1] = new string("abcdefg");
    s[1][2] = new string("abcdefg");
    s[2][0] = new string("abcdefg");
    s[2][1] = new string("abcdefg");
    s[2][2] = new string("abcdefg");

    cout << calcola(s, 3, 3);
}