#include <stdio.h>
#include <stdlib.h>

#define NAME_MAX_LEN 100

/*
 * Структура товара: название, цена за штуку, количество.
 * Три поля — больше, чем в предыдущих заданиях,
 * но принцип работы тот же.
 */
struct product {
    char name[NAME_MAX_LEN];
    int price;
    int quantity;
};

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        return 1;
    }

    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
    }

    struct product* products = malloc((size_t)n * sizeof(*products));
    if (products == NULL) {
        return 1;
    }

    /*
     * Общая сумма — long long, потому что
     * 100 товаров × 10000 цена × 10000 количество = 10^10,
     * что не помещается в int (максимум ~2×10^9).
     */
    long long total = 0;

    for (int i = 0; i < n; i++) {
        /* Читаем название. */
        int len = 0;
        while ((ch = getchar()) != EOF && ch != '\n') {
            if (len < NAME_MAX_LEN - 1) {
                products[i].name[len] = (char)ch;
                len++;
            }
        }
        products[i].name[len] = '\0';

        /* Читаем цену. */
        if (scanf("%d", &products[i].price) != 1) {
            free(products);
            return 1;
        }
        while ((ch = getchar()) != EOF && ch != '\n') {
        }

        /* Читаем количество. */
        if (scanf("%d", &products[i].quantity) != 1) {
            free(products);
            return 1;
        }
        while ((ch = getchar()) != EOF && ch != '\n') {
        }

        /*
         * Считаем сумму для этого товара.
         * Приводим к long long ДО умножения,
         * чтобы само умножение не переполнило int.
         */
        long long line_sum = (long long)products[i].price * products[i].quantity;
        total += line_sum;

        /* Выводим строку товара. */
        if (i > 0) {
            putchar('\n');
        }
        printf("%s %d %d %lld", products[i].name, products[i].price, products[i].quantity, line_sum);
    }

    /* Выводим итог на новой строке. */
    printf("\nTotal %lld", total);

    free(products);
    return 0;
}