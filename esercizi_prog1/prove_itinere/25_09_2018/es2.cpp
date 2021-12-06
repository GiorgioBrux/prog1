#include <iostream>

using namespace std;

int calcola(string *arr, int l) {
    int max = 0;
    for (int i = 0; i < l; i++) {
        int conta = 1;
        for (int j = arr[i].length() / 2 + 1; j < arr[i].length(); j++) {
            cout << "Controllando [" << j << "] con [" << arr[i].length() - j - 1 << "]" << endl;
            if (arr[i][j] == arr[i][arr[i].length() - j - 1])
                conta += 2;
            else
                break;
        }
        cout << "Conta: " << conta << endl;
        if (conta > max) max = conta;
    }
    return max;
}

int main()  // Funzione main non richiesta ai fini dell'esercizio. Usata solo per verificare l'output.
{
    string *arr = new string[2];
    arr[0] = "ABCDCBA";
    arr[1] = "ABCEDECBA";
    cout << calcola(arr, 2);
}