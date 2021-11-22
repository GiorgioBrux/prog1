#include <iostream>

using namespace std;

bool calcolo(int*** arr, int n, int m) {
    int somma = 0;
    for (int i = 0; i < n - 1; i++) {
        somma += *arr[i + 1][m - i - 1];
    }
    if (somma % n == 0)
        return true;
    else
        return false;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
    int*** arr = new int**[2];
    for (int i = 0; i < 5; i++) {
        arr[i] = new int*[5];
        for (int j = 0; j < 2; j++) {
            arr[i][j] = new int;
        }
    }

    *arr[0][0] = 1;
    *arr[0][1] = 2;
    *arr[1][0] = 3;
    *arr[1][1] = 4;
    // 1 2
    // 3 4
    // La 'diagonale sotto quella secondaria' in questo caso è semplicemente 4, che è divisibile per 2.
    cout << calcolo(arr, 2, 2);
}