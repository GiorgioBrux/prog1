#include <iostream>
using namespace std;

bool* funct(string*** S, int n, int m, string x, double* W) {
    bool* R = new bool[m];
    for (int i = 0; i < m; i++) {
        double counter = 0;
        for (int j = 0; j < n; j++) {
            if (S[j][i] == NULL) continue;
            if (S[j][i]->find(x) != string::npos) counter++;
        }
        if (counter / n <= W[i])
            R[i] = true;
        else
            R[i] = false;
    }
    return R;
}