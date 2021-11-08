/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iostream>

using namespace std;

int main() {
    double y = -4.5;  // può anche essere positivo
    double x = 0.5;

    if (x > 1) {
        cout << "X non valido. Esco...";
        return 1;
    }

    cout.precision(4);
    cout << scientific;

    while (y != 0) {
        y = y * x;
        cout << y << endl;
    }

    cout << "Underflow rilevato!" << endl;
}
