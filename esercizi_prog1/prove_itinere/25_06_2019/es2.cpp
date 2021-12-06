#include <iostream>

using namespace std;

bool calcola(string*** A, int n, short m, short k) {
    int conta = 0;
    for (int i = 0; i < n; i++) {
        int vocali = 0;
        for (int j = 0; j < A[i][n - 1 - i]->length(); j++) {
            string str = *A[i][n - 1 - i];
            switch (str[j]) {
                case 'A':
                case 'a':
                case 'E':
                case 'e':
                case 'I':
                case 'i':
                case 'O':
                case 'o':
                case 'U':
                case 'u':
                    vocali++;
                    break;
                default:
                    break;
            }
            if (vocali <= k) conta++;
        }
    }
    if (conta >= m)
        return true;
    else
        return false;
}