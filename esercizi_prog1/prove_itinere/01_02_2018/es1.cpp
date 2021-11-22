#include <iostream>

using namespace std;

int santoro(bool **arr, int n, int m) {
    int x = n / 2;
    int y = m / 2;

    int conta = 0;

    srand(time(NULL));

    while (x < n && y < m) {  // max = 3, min = 0
        cout << "Sono a " << x << "," << y << endl;
        int direzione = rand() % 4;
        switch (direzione) {
            case 0:
                x++;
                break;
            case 1:
                x--;
                break;
            case 2:
                y++;
                break;
            case 3:
                y--;
                break;
        }
        if (arr[x][y]) {
            arr[x][y] = false;  // Abbiamo raccolto il libro sacro
            conta++;
        }
    }

    return conta;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.

    auto **matrice = new bool *[5];
    for (int i = 0; i < 5; i++) {
        *(matrice + i) = new bool[5];
        for (int j = 0; j < 5; j++) {
            matrice[i][j] = rand() % 2;
        }
    }

    cout << santoro(matrice, 5, 5);
}