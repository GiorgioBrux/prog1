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
    cout << "Inserisci due numeri N e M maggiori di 1 separati da uno spazio >> ";
    double N, M;
    cin >> N >> M;

    if (N < 1 || M < 1) {
        cout << "Uno dei due numeri e' minore di uno. Esco...";
        return -1;
    }

    round(N);
    round(M);
    srand(time(0));

    double V[(int)N][(int)M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            V[i][j] = rand();
        }
    }

    double scalare = rand();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << scalare * V[i][j] << " ";
        }
        cout << endl;
    }

    int minimo = min((int)N, (int)M);

    int V2[minimo][minimo];

    for (int i = 0; i < minimo; i++) {
        for (int j = 0; j < minimo; j++) {
            V2[i][j] = V[i][j];
        }
    }
}