/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double a = 0, b = 0;

    while (a == 0) {
        cout << "Inserisci A >> ";
        cin >> a;
    }

    while (b == 0) {
        cout << "Inserisci B >> ";
        cin >> b;
    }

    cout.precision(4);

    cout << scientific << "Media: " << (a + b) / 2 << ", Somma: " << a + b << ", Max" << max(a, b);
}
