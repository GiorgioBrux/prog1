/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iostream>

using namespace std;

int main() {
    double r = 0.0;
    constexpr double pi = 3.14159265358979323846;
    cout << "Inserisci raggio cerchio >> ";
    cin >> r;

    if (r <= 0) {
        cout << "Raggio non valido. Esco..." << endl;
        return -1;
    }

    cout << "Area: " << (pi * r * r) << ", Circonferenza: " << (2 * pi * r) << endl;
}