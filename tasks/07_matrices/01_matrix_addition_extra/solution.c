#include <stdio.h>

int main(void) {
    int n;
    int matrix[10][10];

    if (scanf("%d", &n) != 1 || n < 1 || n > 10) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            if (scanf("%d", &value) != 1) {
                return 0;
            }
            matrix[i][j] += value;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            putchar('\n');
        }
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                putchar(' ');
            }
            printf("%d", matrix[i][j]);
        }
    }

    return 0;
}