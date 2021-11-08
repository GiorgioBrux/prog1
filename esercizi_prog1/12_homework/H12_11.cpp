/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */
#include <iostream>

using namespace std;

int main() {
    int tubi[5];
    int minuti;

    for (int i = 0; i < 5; i++) {
        cout << "Inserisci tubo n." << i + 1 << " (1<=x<=15): ";
        cin >> tubi[i];
        if (tubi[i] < 1 || tubi[i] > 15) {
            cout << "Tubo non valido. Esco..." << endl;
            return -1;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (tubi[i] == tubi[j]) {
                cout << "Tubi non distinti. Esco..." << endl;
                return -1;
            }
        }
    }

    cout << "Inserisci numero minuti >> ";
    cin >> minuti;

    if (minuti < 0) {
        cout << "Minuti negativi non ammessi. Esco..." << endl;
        return -1;
    }

    int acquaA = 0, acquaB = 0, acquaC = 0;

    for (int i = 0; i < 5; i++) {
        switch (tubi[i]) {
            case 2:
            case 4:
            case 8:
                acquaB += 120 * minuti;
                break;
            case 6:
            case 10:
                acquaA += 120 * minuti;
                break;
            case 3:
            case 7:
            case 9:
                acquaB += 60 * minuti;
                break;
            case 1:
            case 5:
                acquaA += 60 * minuti;
                break;
            default:
                if (tubi[i] % 2 == 0)
                    acquaC += 120 * minuti;
                else
                    acquaC += 60 * minuti;
        }
    }

    cout << "Dopo " << minuti << " minuti, le vasche si sono riempite nel seguente modo: " << endl;
    cout << "Vasca A: " << acquaA << " l" << endl;
    cout << "Vasca B: " << acquaB << " l" << endl;
    cout << "Vasca C: " << acquaC << " l" << endl;
}