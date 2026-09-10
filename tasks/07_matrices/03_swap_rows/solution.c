#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n;

    if (scanf("%d %d", &m, &n) != 2 || m <= 0 || n <= 0) {
        printf("n/a");
        return 0;
    }

    int *matrix = malloc((size_t)m * n * sizeof(int));

    if (matrix == NULL) {
        printf("n/a");
        return 0;
    }

    for (int i = 0; i < m * n; i++) {
        if (scanf("%d", &matrix[i]) != 1) {
            free(matrix);
            printf("n/a");
            return 0;
        }
    }

    int min = matrix[0];
    int max = matrix[0];
    int min_row = 0;
    int max_row = 0;

    for (int i = 1; i < m * n; i++) {
        if (matrix[i] < min) {
            min = matrix[i];
            min_row = i / n;
        }

        if (matrix[i] > max) {
            max = matrix[i];
            max_row = i / n;
        }
    }

    for (int j = 0; j < n; j++) {
        int temp = matrix[min_row * n + j];
        matrix[min_row * n + j] = matrix[max_row * n + j];
        matrix[max_row * n + j] = temp;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", matrix[i * n + j]);
        }

        if (i < m - 1) {
            printf("\n");
        }
    }

    free(matrix);

    return 0;
}