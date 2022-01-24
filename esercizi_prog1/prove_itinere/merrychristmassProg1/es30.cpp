#include <iostream>

using namespace std;

bool funct(string** A, int n, int m, unsigned short k, unsigned short s) {
    if (m < k) return false;

    for (int i = 0; i < n; i++) {
        int counter = 0;
        for (int j = 0; j < m; j++) {
            int upper = 0;
            for (int k = 0; k < A[i][j].length(); k++) {
                if (toupper(A[i][j][k]) == A[i][j][k]) upper++;
            }
            if (upper < s) counter++;
        }
        if (counter >= k) return true;
    }
    return false;
}