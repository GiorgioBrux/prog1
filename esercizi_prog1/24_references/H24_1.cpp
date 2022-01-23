#include <iostream>
using namespace std;

class Matrice3D {
   private:
    int x, y, z;
    int*** matrice;

   public:
    Matrice3D(const int X, const int Y, const int Z, const int def = 0) {
        x = X;
        y = Y;
        z = Z;

        matrice = new int**[X];
        for (int i = 0; i < X; i++) {
            matrice[i] = new int*[Y];
            for (int j = 0; j < Y; j++) {
                matrice[i][j] = new int[Z];
                for (int k = 0; k < Z; k++) {
                    matrice[i][j][k] = def;
                }
            }
        }
    }
    int getDimX() { return x; }
    int getDimY() { return y; }
    int getDimZ() { return z; }
    void stampa() {
        for (int k = 0; k < z; k++) {
            cout << "Faccia n." << k << endl;
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    cout << matrice[i][j][k] << " ";
                }
                cout << endl;
            }
        }
    }
    int& getElement(int x, int y, int z) { return matrice[x][y][z]; }
    int getValue(int x, int y, int z) { return matrice[x][y][z]; }
    static Matrice3D* sommaByPtr(Matrice3D* A, Matrice3D* B) {
        const int x = A->x < B->x ? B->x : A->x;
        const int y = A->y < B->y ? B->y : A->y;
        const int z = A->z < B->z ? B->z : A->z;

        Matrice3D* res = new Matrice3D(x, y, z);
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {
                    res->matrice[i][j][k] = (i < A->x && j < A->y && k < A->z ? A->matrice[i][j][k] : 0) +
                                            (i < B->x && j < B->y && k < B->z ? B->matrice[i][j][k] : 0);
                }
            }
        }
        return res;
    }
    static Matrice3D& sommaByReference(Matrice3D& A, Matrice3D& B) {
        const int x = A.x < B.x ? B.x : A.x;
        const int y = A.y < B.y ? B.y : A.y;
        const int z = A.z < B.z ? B.z : A.z;

        Matrice3D* res = new Matrice3D(x, y, z);
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {
                    res->matrice[i][j][k] = (i < A.x && j < A.y && k < A.z ? A.matrice[i][j][k] : 0) +
                                            (i < B.x && j < B.y && k < B.z ? B.matrice[i][j][k] : 0);
                }
            }
        }
        return *res;
    }
    static void sommaByReference(Matrice3D& A, Matrice3D& B, Matrice3D* C) {
        const int x = A.x < B.x ? B.x : A.x;
        const int y = A.y < B.y ? B.y : A.y;
        const int z = A.z < B.z ? B.z : A.z;

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {
                    C->matrice[i][j][k] = (i < A.x && j < A.y && k < A.z ? A.matrice[i][j][k] : 0) +
                                          (i < B.x && j < B.y && k < B.z ? B.matrice[i][j][k] : 0);
                }
            }
        }
    }
};

int main() {
    Matrice3D* A = new Matrice3D(3, 3, 3, 5);
    Matrice3D* B = new Matrice3D(2, 2, 2, 10);

    Matrice3D* C = Matrice3D::sommaByPtr(A, B);
    C->stampa();
}