/* EXAM_03_02. Перевод радиан в градусы: умножаем на 57.29 и округляем. */

#include <math.h>
#include <stdio.h>

int main(void) {
    double radians;

    /* Если чтение не удалось, radians не определён: считать с ним нельзя. */
    if (scanf("%lf", &radians) != 1) {
        printf("n/a");
        return 0;
    }

    /* Угол может быть и отрицательным, поэтому проверки знака нет. */
    double result = radians * 57.29;

    /* Округляем только итог. round() режет по школьным правилам, %.0lf убирает ".0". */
    printf("%.0lf", round(result));

    return 0;
}