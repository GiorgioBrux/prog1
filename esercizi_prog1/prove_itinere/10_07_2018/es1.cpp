#include <iostream>

using namespace std;

bool calcola(char*** arr, int n) {
    for (int i = 0; i < n; i++) {
        bool same = true;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] != arr[i][j]) {
                same = false;
                break;
            }
        }
        if (same) return true;
    }
    return false;
}