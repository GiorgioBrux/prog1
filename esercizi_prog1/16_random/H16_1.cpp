/*
 * Author: giorgiobrux
 * Created Date: Sunday November 7th 2021
 * -----
 * Last Modified: Sun Nov 07 2021
 */
#include <iostream>

using namespace std;

int genera_numero() { return rand() % 6 + 1; }

int main() {
    cout << "Quanti tiri vuoi fare >> ";
    int N;
    cin >> N;

    if (N < 1) {
        cout << "Valore di tiri non valido. Esco...";
        return -1;
    }

    srand(time(0));

    for (int i = 0; i < N; i++) {
        cout << genera_numero() << " " << genera_numero() << endl;
    }
}