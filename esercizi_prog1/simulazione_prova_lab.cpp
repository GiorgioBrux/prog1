#include <math.h>

#include <iostream>
#define DIM 30
using namespace std;

class A {
   protected:
    double* ptr;
    short len;

   public:
    A(short n) : len(n) {
        ptr = new double[n];
        for (int i = 0; i < n; i++) {
            ptr[i] = rand() / (double)RAND_MAX;
        }
    }
    virtual double foo(short a) const = 0;
};

class B : public A {
   private:
    double alpha;
    double extract(short s) const { return ptr[s % len] + alpha / 2; }

   public:
    B(short m, double d) : alpha(d), A(m){};
    double foo(short b) const { return log(1 + extract(b)); }
    friend ostream& operator<<(ostream& output, const B& x);
};

template <class T>
class C : public A {
   private:
    T x;

   public:
    T g(T k) const { return 3 * k; }
    C(short n) : A(n) {
        if (typeid(short) == typeid(x))
            x = g(n);
        else
            x = log(1 + n);
    }
    double foo(short r) const { return g(r * x); }
};

ostream& operator<<(ostream& output, A& a) { return output; }

int main() {

    srand(328832748);
    A* vett[DIM];
    for (int i = 0; i < DIM; i++) {
        short n = 1 + rand() % 5;
        switch (rand() % 3) {
            case 0:
                vett[i] = new B(n, n / 100.0);
                break;
            case 1:
                vett[i] = new C<double>(n);
                break;
            case 2:
                vett[i] = new C<int>(n);
        }
    }
}