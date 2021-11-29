#include <iostream>

using namespace std;

bool calcola(bool **arr1, bool **arr2, bool **arr3, int n, int m) {
    bool calc = true;

    for (int i = 0; i < n - 1; i++) {
        cout << "Controllo [" << i + 1 << "][" << m - i - 1 << "]" << endl;
        if (arr1[i + 1][m - i - 1] != arr2[i + 1][m - i - 1] || arr2[i + 1][m - i - 1] != arr3[i + 1][m - i - 1]) {
            calc = false;
            break;
        }
    }
    return calc;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
    bool **arr1 = new bool *[2];
    bool **arr2 = new bool *[2];
    bool **arr3 = new bool *[2];

    for (int i = 0; i < 2; i++) {
        *(arr1 + i) = new bool[2];
        *(arr2 + i) = new bool[2];
        *(arr3 + i) = new bool[2];
    }

    arr1[0][0] = false;
    arr1[0][1] = true;
    arr1[1][0] = false;
    arr1[1][1] = false;

    arr2[0][0] = true;
    arr2[0][1] = true;
    arr2[1][0] = true;
    arr2[1][1] = false;

    arr3[0][0] = false;
    arr3[0][1] = true;
    arr3[1][0] = false;
    arr3[1][1] = false;

    cout << calcola(arr1, arr2, arr3, 2, 2) << endl;
}