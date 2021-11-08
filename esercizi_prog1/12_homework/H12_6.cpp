/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */
//
// Created by giorg on 31/10/2021.
//

#include <iostream>

using namespace std;

double round(double toround) {
    int parte_intera = static_cast<int>(toround);
    double decimal = toround - parte_intera;
    return decimal > 0.5 ? parte_intera + 1 : parte_intera;
}

int main() {
    double a = 0, b = 0, c = 0;

    while (a == 0) {
        cout << "Inserisici A >> ";
        cin >> a;
    }

    while (b == 0) {
        cout << "Inserisici B >> ";
        cin >> b;
    }

    while (c == 0) {
        cout << "Inserisici C >> ";
        cin >> c;
    }

    cout << "A: " << round(a) << ", B: " << round(b) << ", C: " << round(c);
}