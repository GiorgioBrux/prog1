/*
 * Author: giorgiobrux
 * Created Date: Friday November 5th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

// Trovare il massimo di 3 variabili usando l'operatore condizionale

#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "Inserisci 3 numeri: ";
    cin >> a >> b >> c;

    cout << "Il massimo e': " << (a > b ? (a > c ? a : c) : (b > c ? b : c))
         << endl;
}
