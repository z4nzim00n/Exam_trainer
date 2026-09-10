/*
 * EXAM_06_05. Квадраты чисел по спирали.
 *
 * Заполняем квадратную матрицу N x N квадратами чисел от 0 до (N^2 - 1).
 * Направление спирали: против часовой стрелки.
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
    
    /* Число, квадрат которого будем записывать в ячейки */
    int num = 0;

    /* Цикл работает, пока мы не заполним все N*N ячеек */
    while (num < n * n) {
        /* 1. Идём ВНИЗ по левой границе */
        for (int i = top; i <= bottom && num < n * n; i++) {
            matrix[i * n + left] = num * num;
            num++;
        }
        left++; /* Левая граница сдвигается вправо */

        /* 2. Идём ВПРАВО по нижней границе */
        for (int i = left; i <= right && num < n * n; i++) {
            matrix[bottom * n + i] = num * num;
            num++;
        }
        bottom--; /* Нижняя граница сдвигается вверх */

        /* 3. Идём ВВЕРХ по правой границе */
        for (int i = bottom; i >= top && num < n * n; i--) {
            matrix[i * n + right] = num * num;
            num++;
        }
        right--; /* Правая граница сдвигается влево */

        /* 4. Идём ВЛЕВО по верхней границе */
        for (int i = right; i >= left && num < n * n; i--) {
            matrix[top * n + i] = num * num;
            num++;
        }
        top++; /* Верхняя граница сдвигается вниз */
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