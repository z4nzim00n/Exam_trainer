#include <stdio.h>

int main(void) {
    int number;
    int reversed = 0;

    if (scanf("%d", &number) != 1) {
        return 0;
    }

    while (number > 0) {
        /*
         * number % 10 получает последнюю цифру исходного числа.
         * Умножение результата на 10 освобождает место справа.
         */
        reversed = reversed * 10 + number % 10;

        /* Убираем уже обработанную последнюю цифру. */
        number /= 10;
    }

    /*
     * Для исходного нуля цикл не выполнится,
     * и reversed останется равным 0.
     */
    printf("%d", reversed);
    return 0;
}