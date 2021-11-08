/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <math.h>

#include <iostream>

using namespace std;

int main() {
    double a, b;

    cout << "Inserisci la lunghezza dei due cateti >> ";
    cin >> a >> b;

    if (a < 0 || b < 0) {
        cout << "Lunghezza dei cateti non valida!" << endl;
        return -1;
    }

    cout << "L\'ipotenusa e\' uguale a " << sqrt(a * a + b * b) << endl;
}