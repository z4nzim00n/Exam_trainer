#include <stdio.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    /* Берем модуль числа, чтобы цифры не зависели от знака */
    int value;
    if (n < 0) {
        value = -n;
    } else {
        value = n;
    }

    /* Последовательно «срезаем» последнюю цифру делением на 10 */
    int last = value % 10; /* последняя цифра */
    value = value / 10;
    int middle = value % 10; /* средняя цифра   */
    value = value / 10;
    int first = value % 10; /* первая цифра    */

    /* Минус выводим, только если число отрицательное */
    if (n < 0) {
        putchar('-');
    }

    /* Печатаем цифры в порядке reversal: последняя, средняя, первая */
    printf("%d%d%d", last, middle, first);

    return 0;
}
