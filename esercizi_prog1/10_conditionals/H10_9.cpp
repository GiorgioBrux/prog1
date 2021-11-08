/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sun Nov 07 2021
 */
#include <iostream>

using namespace std;

int main() {
    // L'operatore NOT ha la precedenza maggiore, l'OR quella minore.
    cout << (!1 || 0 && 1 || 0);
}