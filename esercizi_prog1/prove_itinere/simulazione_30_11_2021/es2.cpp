#include <iostream>

using namespace std;

bool* calcola(string** A, int n, int m, string*** B, int l) {
    bool* array = new bool[l];
    for(int i=0; i<l; i++){
       array[i] = false;
    }

    for (int j = 0; j < l; j++) {
        for (int k = 0; k < m; k++) {
            if (B[k][j] == nullptr) continue;
            string s = *B[k][j];
            if (A[j][k].find(s) != std::string::npos) {
                array[j] = true;
                break;
            }
        }
    }
    return array;
}