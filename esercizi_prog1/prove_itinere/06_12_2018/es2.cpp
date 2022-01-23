#include <iostream>

using namespace std;

bool* calcola(string*** arr, int n, int m, short k, string s) {
    bool* ret = new bool[n];

    for (int i = 0; i < n; i++) {
        int conta = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j]->find(s) != string::npos) conta++;
        }
        if (conta >= k)
            ret[i] = true;
        else
            ret[i] = false;
    }
    return ret;
}