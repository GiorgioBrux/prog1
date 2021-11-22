#include <iostream>

using namespace std;

bool calcola(string*** arr, int n, int m, short a, short b, string s) {
    for (int i = 0; i < m; i++) {
        int nStr = 0;
        for (int j = 0; j < n; j++) {
            string str = *arr[j][i];
            if (str.contains(s)) nStr++;  // Supportato solo dal C++23, usa -std=c++2b su clang/gcc
        }
        if (nStr >= a && nStr <= b) return true;
    }
    return false;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
    auto*** matrice = new string**[2];
    for (int i = 0; i < 5; i++) {
        *(matrice + i) = new string*[2];
        for (int j = 0; j < 5; j++) {
            matrice[i][j] = new string;
        }
    }

    *matrice[0][0] = "diodaw";
    *matrice[1][0] = "dioddd";
    *matrice[0][1] = "aaabbbb";
    *matrice[1][1] = "abbbbbb";
    // diodaw aaabbbb
    // dioddd abbbbbb

    cout << calcola(matrice, 2, 2, 1, 1, "dio") << endl << "Esco...";
}