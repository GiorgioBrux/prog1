#include <iostream>

using namespace std;

bool calcola(short **arr, int n) {
    bool superiore = true, inferiore = true;

    // Triangolare superiore?
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "SUP: Controllo arr[" << i << "][" << j << "]" << endl;
            if (arr[i][j] == 0) superiore = false;
        }
        if (!superiore) break;
    }
    if (superiore) return true;

    // Triangolare inferiore?
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            cout << "INF: Controllo arr[" << i << "][" << j << "]" << endl;
            if (arr[i][j] == 0) inferiore = false;
        }
        if (!inferiore) break;
    }
    if (inferiore) return true;

    return false;
}

int main()  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
{
    short **arr = new short *[2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new short[2];
    }
    arr[0][0] = 5;
    arr[0][1] = 5;
    arr[1][0] = 0;
    arr[1][1] = 5;
    // 5 5
    // 0 5
    cout << calcola(arr, 2) << endl;  // Output: 1

    arr[0][0] = 0;
    arr[0][1] = 5;
    arr[1][0] = 0;
    arr[1][1] = 5;
    // 0 5
    // 0 5
    cout << calcola(arr, 2) << endl;  // Output: 0

    arr[0][0] = 5;
    arr[0][1] = 0;
    arr[1][0] = 5;
    arr[1][1] = 5;
    // 5 0
    // 5 5
    cout << calcola(arr, 2) << endl;  // Output: 1
}