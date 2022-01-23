#include <iostream>

using namespace std;

int funct(string* A, int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        int centro = A[i].length() / 2;
        int ctr = 1;
        for (int j = 1; j < A[i].length() - centro; j++) {
            if (A[i][centro + j] == A[i][centro - j])
                ctr += 2;
            else
                break;
                }
        if (max < ctr) max = ctr;
    }
    return max;
}

int main() {
    string* A = new string[2];

    A[0] = "oro";
    A[1] = "ABBBA";

    cout << funct(A, 2);
}