#include <iostream>

using namespace std;

bool calcola(string*** Q, int n, string s) {
    int conta_princ = 0;
    int conta_secon = 0;

    for (int i = 0; i < n; i++) {
        if (Q[i][i]->find(s) != std::string::npos) conta_princ++;
        if (Q[i][n - i - 1]->find(s) != std::string::npos) conta_secon++;
    }
    if (conta_princ > conta_secon)
        return true;
    else
        return false;
}

int main() {  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.

    string*** arr = new string**[2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new string*[2];
        for (int j = 0; j < 2; j++) {
            arr[i][j] = new string;
        }
    }

    *arr[0][0] = "prova";
    *arr[0][1] = "prova";
    *arr[1][0] = "prova";
    *arr[1][1] = "paodkadw";

    // prova prova
    // prova paodwdad
    cout << calcola(arr, 2, "prova") << endl;  // Output: 0

    *arr[1][0] = "adjiawda";
    *arr[1][1] = "prova";
    // prova prova
    // paodawd prova
    cout << calcola(arr, 2, "prova");  // Output: 1
}