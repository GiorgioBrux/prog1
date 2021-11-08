/*
 * Author: giorgiobrux
 * Created Date: Saturday November 6th 2021
 * -----
 * Last Modified: Sat Nov 06 2021
 */

#include <iostream>

using namespace std;

int main() {
    string s1, s2, s3, mys;

    if (s1.length() > 10 && s2.length() > 10 && s3.length() > 10) {
        if (s1.length() > 20 || s2.length() > 20 || s3.length() > 20) {
            mys = s2[0] + s2[1] + s2[2] + s3[s3.length() - 3] + s3[s3.length() - 2] + s3[s3.length() - 1];
        } else {
            mys = s1 + s2 + s3;
        }
        cout << mys << endl;
    } else {
        cout << s1.length() + s2.length() + s3.length() << endl;
    }
}