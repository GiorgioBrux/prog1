/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iostream>

using namespace std;

int main() {
    cout << "Inserisci le due stringhe da comparare separate da uno spazio: ";
    string s1, s2;
    cin >> s1 >> s2;
    cout << "'" << s1 << "'" << (s1 < s2 ? " < " : " > ") << "'" << s2 << "'" << endl;
}