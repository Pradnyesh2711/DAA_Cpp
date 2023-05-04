#include <stdio.h>

int dp[20][20];
int s[20][20];

void matrixo(int *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        dp[i][i] = 0;
    }
    for (int k = 1; k < n - 1; k++) {
        for (int i = 0; i < n - k; i++) {
            int j = i + k;
            dp[i][j] = 999999;
            for (int x = i; x < j; x++) {
                int q = dp[i][x] + dp[x + 1][j] + p[i] * p[j + 1] * p[x + 1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    s[i][j] = x;
                }
            }
        }
    }
}

int main() {
    int n = 7;
    int p[] = {4, 10, 3, 12, 20, 7};
    matrixo(p, n);
    for (int i = 0; i < n - 2; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < n - 2; j++) {
            if (dp[i][j] != 0) {
                printf("%d ", dp[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>

int dp[20][20];
int s[20][20];

void matrixo(int *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        dp[i][i] = 0;
    }
    for (int k = 1; k < n - 1; k++) {
        for (int i = 0; i < n - k; i++) {
            int j = i + k;
            dp[i][j] = 999999;
            for (int x = i; x < j; x++) {
                int q = dp[i][x] + dp[x + 1][j] + p[i] * p[j + 1] * p[x + 1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    s[i][j] = x;
                }
            }
        }
    }
}

int main() {
    int n = 7;
    int p[] = {4, 10, 3, 12, 20, 7};
    matrixo(p, n);
    for (int i = 0; i < n - 2; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < n - 2; j++) {
            if (dp[i][j] != 0) {
                printf("%d ", dp[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

