/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <cmath>
#include <iostream>
using namespace std;

double calcola_formula(int B, double L, double P, double Q) { return (B + max(0.0, (L - 1)) * P) * Q; }

double calcola_completo(string ambiente, double L, int carico) {
    bool castano = (ambiente == "esterno");
    double Q;
    if (carico > 100 && castano)
        Q = 1.1;
    else if (carico > 80 && !castano)
        Q = 1.2;
    else
        Q = 1.0;

    return calcola_formula(castano ? 0.018 : 0.02, L, castano ? 0.02 : 0.022, Q);
}

int main() {
    string ambiente;
    while (ambiente != "esterno" && ambiente != "interno") {
        cout << "Inserisci tipo di ambiente (esterno/interno) >> ";
        cin >> ambiente;
    }

    double L = 0;
    while (L == 0) {
        cout << "Inserisci lunghezza (m) >> ";
        cin >> L;
    }

    int carico = 0;
    while (carico == 0) {
        cout << "Inserisci masssimo carico del singolo ripiano >> ";
        cin >> carico;
    }

    cout << "Usando il " << (ambiente == "esterno" ? "castano" : "pino") << endl;
    cout << "Spessore ripiani: " << calcola_completo(ambiente, L, carico) << endl;
}