#include <iostream>

using namespace std;

string calcola(string ***arr, int n, int m) {
    string output = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int length = arr[i][j][0].length();
            cout << "Lunghezza: " << length << endl;
            cout << "Carattere ultimo: " << arr[i][j][0][length - 1] << endl;
            output += ", ";
            output += string(1, arr[i][j][0][length - 2]);
            output += string(1, arr[i][j][0][length - 1]);
        }
    }
    cout << output << endl;
    return output;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
    auto ***matrice = new string **[2];
    for (int i = 0; i < 2; i++) {
        *(matrice + i) = new string *[2];
        for (int j = 0; j < 2; j++) {
            matrice[i][j] = new string[2];
        }
    }

    matrice[0][0][0] = "diocane";
    matrice[0][1][0] = "prova";
    matrice[1][0][0] = "test";
    matrice[1][1][0] = "vivailcpp";

    cout << calcola(matrice, 2, 2) << endl;
}