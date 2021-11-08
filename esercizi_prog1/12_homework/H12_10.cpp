/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iostream>

using namespace std;

double calcola_zucchero(double zucchero, bool diabetici) { return diabetici ? 2.0 / 3.0 * zucchero : zucchero; }

int main() {
    int N = 0;
    bool diabetici;

    while (N == 0) {
        cout << "Inserisci il numero di persone (2<=x<=16): ";
        cin >> N;
    }

    cout << "Sono presenti diabetici? (1/0) ";
    cin >> diabetici;

    switch (N) {
        case 2 ... 4:
            cout << "Dosaggio: 0.3kg farina, 4 uova, " << calcola_zucchero(0.1, diabetici) << "kg "
                 << (diabetici ? "fruttosio" : "zucchero") << endl;
            break;
        case 5 ... 8:
            cout << "Dosaggio: 0.75kg farina, 10 uova, " << calcola_zucchero(0.15, diabetici) << "kg "
                 << (diabetici ? "fruttosio" : "zucchero") << endl;
            break;
        case 9 ... 16:
            cout << "Dosaggio: 1.05kg farina, 14 uova, " << calcola_zucchero(0.25, diabetici) << "kg "
                 << (diabetici ? "fruttosio" : "zucchero") << endl;
            break;
    }
}
