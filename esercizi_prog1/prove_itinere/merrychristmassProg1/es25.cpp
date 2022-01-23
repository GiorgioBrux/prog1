#include <iostream>

using namespace std;

bool funct(int** M, int n, int m, short k, double x) {
    for (int i = 0; i < m; i++) {
        int coppieAd = 0;
        for (int j = 0; j < n - 1; j++) {
            if (M[j + 1][i] == 0) continue;
            if (static_cast<double>(M[j][i]) / M[j + 1][i] < x) coppieAd++;
        }
        if (coppieAd == k) return true;
    }
    return false;
}

int main() {
    int** M = new int*[2];
    for (int i = 0; i < 2; i++) {
        M[i] = new int[2];
    }

    M[0][0] = 1;
    M[0][1] = 5;
    M[1][0] = 1;
    M[1][1] = 5;

    // 1 5
    // 1 5

    cout << funct(M, 2, 2, 1, 10);
}