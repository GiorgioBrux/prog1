/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iostream>

using namespace std;

int main() {
    cout << "Inserisci un carattere: ";
    char c;
    cin >> c;

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        cout << static_cast<int>(c);
    } else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        cout << c;
    } else if (1 <= (c - '0') && (c - '0') <= 10) {
        cout << (c - '0') * 10;
    }
}