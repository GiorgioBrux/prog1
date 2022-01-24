/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice di puntatori a stringhe
di dimensioni n*m e tre short k, r ed s (si assuma r < s e k < n). Il metodo restituisca
il numero di colonne aventi il seguente requisito: la colonna contiene almeno k stringhe
palindrome che abbiano lunghezza r <= l <= s. NB: Una stringa si dice palindroma quando si
legge allo stesso modo da destra e da sinistra (esempio "abekeba" oppure "trert") */

#include <iostream>
using namespace std;

int funct(string*** A, int n, int m, short k, short r, short s) {
    int res = 0;
    for (int i = 0; i < m; i++) {
        int conta = 0;
        for (int j = 0; j < n; j++) {
            if (A[j][i] == NULL) continue;
            int lun = A[j][i]->length();
            if (lun < r || lun > s) continue;

            bool pal = true;
            string str = *A[j][i];
            for (int l = 0; l < lun; l++) {
                if (str[l] != str[lun - l - 1]) {
                    pal = false;
                    break;
                }
            }
            if (pal) conta++;
        }
        if (conta >= k) res++;
    }
    return res;
}