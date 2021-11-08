/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iostream>

using namespace std;

int main() {
    cout << "Provo a stampare 2.0/0: " << 2.0 / 0 << endl;
    cout << "Provo a stampare 2/0: " << 2 / 0 << endl;

    // Nel primo caso, Se il compilatore segue lo standard IEEE 754 (quello della virgola mobile) allora stampera'
    // infinito. poiche' nello standard sono riservate delle combinazioni di bit per esprimere questi valore.

    // Nel secondo caso, non vi sono questi bit riservati.
    // È quindi undefined behaviour, ed e' probabile che il programma crashi senza stampare nulla.

    // Output di esempio con g++ 11:
    // Provo a stampare 2.0/0: inf
    // Floating point exception
}