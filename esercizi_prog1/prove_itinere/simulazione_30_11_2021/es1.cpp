#include <iostream>

using namespace std;

bool calcola(unsigned int*** arr, int n, double w, short k) {
    int soddisfa = 0;
    for (int i = 0; i < n; i++) {
        double media = 0;
        int validi = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] != nullptr) {
                unsigned int num = *arr[j][i];
                media += num;
                validi++;
            }
        }
        if(validi > 0){
            media = media / validi;
            if (media <= w) soddisfa++;
        }
    }
    if (soddisfa >= k) return true;
    return false;
}