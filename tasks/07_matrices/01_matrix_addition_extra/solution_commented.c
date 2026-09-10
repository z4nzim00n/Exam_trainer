#include <stdio.h>

int main(void) {
    int n;

    /* По условию размер матриц не превышает 10 x 10. */
    int matrix[10][10];

    if (scanf("%d", &n) != 1 || n < 1 || n > 10) {
        return 0;
    }

    /* Сначала сохраняем матрицу A. */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 0;
            }
        }
    }

    /*
     * Элементы B читаем по одному и сразу прибавляем
     * к соответствующим элементам сохранённой матрицы.
     */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            if (scanf("%d", &value) != 1) {
                return 0;
            }
            matrix[i][j] += value;
        }
    }

    /* Теперь matrix содержит сумму A + B. */
    for (int i = 0; i < n; i++) {
        /* Переносы печатаем между строками, а не после последней. */
        if (i > 0) {
            putchar('\n');
        }

        for (int j = 0; j < n; j++) {
            /* Пробелы печатаем только между элементами строки. */
            if (j > 0) {
                putchar(' ');
            }
            printf("%d", matrix[i][j]);
        }
    }

    return 0;
}