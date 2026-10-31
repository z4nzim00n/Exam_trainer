/*
 * EXAM_08_06. Сумма длин векторов.
 *
 * Читаем N векторов и число D, суммируем длины тех векторов,
 * которые строго длиннее D, и выводим сумму, округлённую до целого.
 */

#include <math.h>
#include <stdio.h>

/* Структура: три целых координаты. */
typedef struct {
    int x;
    int y;
    int z;
} Vector;

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
        return 0;
    }

    Vector vectors[n];

    for (int i = 0; i < n; i++) {
        /* Три числа за один scanf. У каждого & — это числа, а не строки. Должно прочитаться ровно 3. */
        if (scanf("%d %d %d", &vectors[i].x, &vectors[i].y, &vectors[i].z) != 3) {
            printf("n/a");
            return 0;
        }
    }

    /* D бывает дробным, поэтому double и формат %lf. */
    double d;
    if (scanf("%lf", &d) != 1) {
        printf("n/a");
        return 0;
    }

    double sum = 0; /* сумма длин подходящих векторов */

    for (int i = 0; i < n; i++) {
        /*
         * Переносим координаты в double. Так умножение x * x не переполнит int
         * и корень считается по вещественным числам.
         */
        double x = vectors[i].x;
        double y = vectors[i].y;
        double z = vectors[i].z;
        double length = sqrt(x * x + y * y + z * z);

        /* Строго больше: вектор длины ровно D не входит в сумму. */
        if (length > d) {
            sum += length;
        }
    }

    /*
     * round делает математическое округление, а %.0f печатает число без дробной части.
     * Если подходящих векторов не было, sum равна 0, и выведется 0.
     */
    printf("%.0f", round(sum));

    return 0;
}