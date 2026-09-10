/*
 * EXAM_06_04. Спираль в матрице.
 *
 * Заполняем квадратную матрицу N x N числами от 1 до N^2 по спирали.
 * Используем 4 границы, которые сужаются к центру после каждого прохода.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
        return 0;
    }

    int *matrix = malloc((size_t)n * n * sizeof(int));

    if (matrix == NULL) {
        printf("n/a");
        return 0;
    }

    /* Инициализируем границы матрицы */
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    /* Число, которое будем записывать в ячейки */
    int num = 1;

    /* Цикл работает, пока мы не заполним все N*N ячеек */
    while (num <= n * n) {
        /* 1. Идём вправо по верхней границе */
        for (int i = left; i <= right && num <= n * n; i++) {
            matrix[top * n + i] = num++;
        }
        top++; /* Верхняя граница сдвигается вниз */

        /* 2. Идём вниз по правой границе */
        for (int i = top; i <= bottom && num <= n * n; i++) {
            matrix[i * n + right] = num++;
        }
        right--; /* Правая граница сдвигается влево */

        /* 3. Идём влево по нижней границе */
        for (int i = right; i >= left && num <= n * n; i--) {
            matrix[bottom * n + i] = num++;
        }
        bottom--; /* Нижняя граница сдвигается вверх */

        /* 4. Идём вверх по левой границе */
        for (int i = bottom; i >= top && num <= n * n; i--) {
            matrix[i * n + left] = num++;
        }
        left++; /* Левая граница сдвигается вправо */
    }

    /* Стандартный вывод матрицы без пробелов в конце строк и без \n в конце */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", matrix[i * n + j]);
        }
        if (i < n - 1) {
            printf("\n");
        }
    }

    free(matrix);

    return 0;
}