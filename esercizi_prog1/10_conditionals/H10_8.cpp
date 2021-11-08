/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iostream>

using namespace std;

int main() {
    // Modifica queste variabili per testare il programma
    bool a = true;
    bool b = true;

    bool xor_gate = (a || b) && !(a && b);

    cout << "Valori iniziali: " << a << ", " << b << endl;

    cout << "XOR: " << xor_gate;
}