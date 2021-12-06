#include <iostream>

using namespace std;

string* func(char*** P, int n, int m, unsigned short* S, unsigned int* W, int l) {
    string* ris = new string[l];
    for (int i = 0; i < l; i++) {
        int r = S[i] % n;
        for (int j = 0; j < W[i]; j++) {
            int c;
            do {
                c = rand() % m;
            } while (P[r][c] == nullptr);

            ris[i] += *P[r][c];
        }
    }
    return ris;
}
