/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iostream>
#include <sstream>

using namespace std;

void sorta_array_stringhe(string arr[3]) {
    if (arr[2].length() < arr[1].length()) {
        string tmp = arr[2];
        arr[2] = arr[1];
        arr[1] = tmp;
    }

    if (arr[1].length() < arr[0].length()) {
        string tmp = arr[1];
        arr[1] = arr[0];
        arr[0] = tmp;
    }

    // In alternativa si può usare questo ma il professore non lo ha spiegato
    // std::sort(arr, arr+3, [](string &s1, string &s2) {return s1.size() <
    // s2.size(); });
}

int main() {
    string input;
    getline(cin, input);

    stringstream ss(input);
    string stringhe[3];
    double double1, double2;

    ss >> stringhe[0] >> stringhe[1] >> stringhe[2] >> double1 >> double2;

    if (double1 > double2)
        cout << double2 << " " << double1;
    else
        cout << double1 << " " << double1;

    sorta_array_stringhe(stringhe);

    cout << " " << stringhe[0] << " " << stringhe[1] << " " << stringhe[2];
}