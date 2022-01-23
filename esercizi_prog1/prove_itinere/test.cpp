#include <iostream>

using namespace std;

int main() {
    double** sex = new double*[5];
    for (int i = 0; i < 5; i++) {
        sex[i] = new double;
    }

    string** foo = new string*[5];
    for (int i = 0; i < 5; i++) {
        foo[i] = new string("hunter2");
    }

    const char** bar = new const char*[5];
    for (int i = 0; i < 5; i++) {
        bar[i] = "hunter2";
        // bar[i] = (char*) "hunter2";
    }

    for (int i = 0; i < 5; i++) {
        cout << bar[i];
    }
}