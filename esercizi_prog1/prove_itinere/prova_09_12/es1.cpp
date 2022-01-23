int calc(int*** arr, int n, int m, double z, short k) {
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - k; j++) {
            int conta = 0, media = 0;
            for (int l = j; l < j + k; l++) {
                if (arr[l][i] != nullptr) {
                    conta++;
                    media += *arr[l][i];
                } else {
                    j = l + 1;
                    break;
                }
            }
            if ((double)media / conta < z) {
                res++;
                break;
            }
        }
    }

    return res;
}