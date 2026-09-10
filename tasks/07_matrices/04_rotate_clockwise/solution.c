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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) {
                printf(" ");
            }
            
            int orig_row = m - 1 - j;
            int orig_col = i;
            printf("%d", matrix[orig_row * n + orig_col]);
        }
        
        if (i < n - 1) {
            printf("\n");
        }
    }

    free(matrix);

    return 0;
}