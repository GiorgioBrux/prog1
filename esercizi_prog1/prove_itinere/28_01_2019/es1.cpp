using namespace std;

bool calcola(int **A, int n, double w) {
    int min = A[0][n - 1];
    int max = A[0][n - 1];
    for (int i = 1; i < n; i++) {
        if (A[i][n - 1 - i] < min) min = A[i][n - 1 - i];
        if (A[i][n - 1 - i] > max) max = A[i][n - 1 - i];
    }
    if ((double)min / max <= w)
        return true;
    else
        return false;
}