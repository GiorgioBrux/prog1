/*
 * Author: giorgiobrux
 * Created Date: Sunday November 7th 2021
 * -----
 * Last Modified: Sun Nov 07 2021
 */
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int p;
    cout << "Inserisci p: ";
    cin >> p;

    if (p < 1) {
        cout << "ERRORE: p è minore di 1. Esco...";
        return -1;
    }

    srand(time(0));

    round(p);
    unsigned int V[p];

    for (int i = 0; i < p; i++) {
        V[i] = rand();
    }

    int i = 0;
    while (i < p) {
        V[i] = rand();
        i++;
    }

    i = 0;
    do {
        V[i] = rand();
        i++;
    } while (i < p);

    for (int i = 0; i < p; i++) {
        cout << V[i] << endl;
    }
}