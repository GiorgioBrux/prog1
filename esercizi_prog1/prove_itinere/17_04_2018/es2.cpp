#include <iostream>
using namespace std;

string *func() {
    string *B = new string[5];
    B[0] = "ciao";
    return B;
}

int main() {
    int *arr = new int(5);
    cout << *arr;
}