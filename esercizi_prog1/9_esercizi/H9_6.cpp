/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iostream>

using namespace std;

int main() {
    const int N = 2;
    const int M = 2;

    int V[N][M] = {0, 2, 3, 4};
    int s = 5;
    int z = 3;

    int W[M];

    for (int i = 0; i < M; i++) {
        W[i] = 0;
        for (int k = 0; k < N; k++) {
            int somma = 0;
            for (int l = 0; l < z; l++) {
                if (k + l < N) {
                    somma += V[k + l][i];
                }
            }
            if (somma >= s) {
                W[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < M; i++) cout << W[i] << " ";

    return 0;
}
