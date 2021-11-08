/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    string str;

    cout << "Inserisci due numeri interi: ";
    cin >> a >> b >> c;

    cout << "Inserisci una stringa: ";
    cin >> str;

    if (a != c && str.length() < 8) {
        b = a + c;
    } else if (a == c && str.length() < 8) {
        b = a - c;
    } else {
        a = 0;
        b = 0;
        c = 0;
    }

    cout << "a: " << b << ", b:" << b << ", c:" << c << endl;
}