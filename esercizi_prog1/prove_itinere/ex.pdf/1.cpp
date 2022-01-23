#include <iostream>

using namespace std;

bool func(int ***A, int k, int n, double w) {
    for (int i = 0; i < k; i++) {
        int max_p = A[i][0][0];
        int min_p = max_p;
        int max_s = A[i][0][n - 1];
        int min_s = max_p;
        for (int j = 0; j < n; j++) {
            int princ = A[i][j][j];
            int sec = A[i][j][n - j - 1];

            if (princ < min_p) min_p = princ;
            if (max_p < princ) max_p = princ;

            if (sec < min_s) min_s = sec;
            if (max_s < sec) max_s = sec;
        }
        double media_p = static_cast<double>(max_p + min_p) / 2;
        double media_s = static_cast<double>(max_s + min_s) / 2;
        if (media_p <= w && media_s <= w) return true;
    }
    return false;
}