#include <iostream>

using namespace std;

string* calcola(string** A, int n, int m) {
    string* res = new string("");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j].length() < A[j % n][i % m].length() + i + j) continue;
            for (int k = 0; k < A[i][j].length(); k++) {
                switch (A[i][j][k]) {
                    case 'A':
                        *res += "A";
                        break;
                    case 'a':
                        *res += "a";
                        break;
                    case 'E':
                        *res += "E";
                        break;
                    case 'e':
                        *res += "e";
                        break;
                    case 'I':
                        *res += "I";
                        break;
                    case 'i':
                        *res += "i";
                        break;
                    case 'O':
                        *res += "O";
                        break;
                    case 'U':
                        *res += "U";
                        break;
                    case 'u':
                        *res += "u";
                        break;
                }
            }
        }
    }

    return res;
}