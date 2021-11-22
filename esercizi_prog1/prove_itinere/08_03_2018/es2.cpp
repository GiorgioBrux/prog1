#include <iostream>

using namespace std;

bool calcolo(string **arr, int n, int m, short w) {
    for (int i = 0; i < n; i++) {
        char tmp[w];
        for (int j = 0; j < w; j++) {
            tmp[j] = arr[i][0][j];
        }
        for (int j = 1; j < m; j++) {
            bool uguali = true;
            for (int k = 0; k < w; k++) {
                if (tmp[k] != arr[i][0][arr[i][0].length() - w + k]) {
                    uguali = false;
                    break;
                }
            }
            if (uguali) return true;
        }
    }
    return false;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
    auto **matrice = new string *[2];
    for (int i = 0; i < 2; i++) {
        *(matrice + i) = new string[2];
    }

    matrice[0][0] = "propro";
    matrice[0][1] = "propro";
    matrice[1][0] = "adawdhawu";
    matrice[1][1] = "okgpdrgdr";

    cout << calcolo(matrice, 2, 2, 3) << endl;  // Output: 1
}
