/*
 * Author: giorgiobrux
 * Created Date: Sunday November 7th 2021
 * -----
 * Last Modified: Sun Nov 07 2021
 */
#include <iostream>

using namespace std;

int main() {
    cout << "Inserisci il numero di iterazioni (N>0) >> ";
    int N;
    cin >> N;

    if (N <= 0) {
        cout << "Numero non valido. Esco...";
    }

    double x, y;
    int S = 0;

    for (int i = 0; i < N; i++) {
        x = rand() / (RAND_MAX * 1.0);
        y = rand() / (RAND_MAX * 1.0);
        if (x * x + y * y <= 1) S++;
        cout << "n." << i + 1 << ", S=" << S << ", T=" << i + 1 << ", pi: " << (double)S / (i + 1) * 4.0 << endl;
    }
}