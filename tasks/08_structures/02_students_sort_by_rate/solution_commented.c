#include <stdio.h>
#include <stdlib.h>

#define NAME_MAX_LEN 100

/*
 * Структура студента — та же, что и в задании 08_01.
 * Имя фиксированного размера + оценка.
 */
struct student {
    char name[NAME_MAX_LEN];
    int rate;
};

int main(void) {
    int n;

    /* Читаем количество студентов. */
    if (scanf("%d", &n) != 1 || n < 1) {
        return 1;
    }

    /* Съедаем '\n' после числа, чтобы не мешало чтению имени. */
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
    }

    /* Выделяем массив под N студентов. */
    struct student* students = malloc((size_t)n * sizeof(*students));
    if (students == NULL) {
        return 1;
    }

    /* Читаем данные каждого студента. */
    for (int i = 0; i < n; i++) {
        /* Имя читаем посимвольно, чтобы обработать пробелы внутри. */
        int len = 0;
        while ((ch = getchar()) != EOF && ch != '\n') {
            if (len < NAME_MAX_LEN - 1) {
                students[i].name[len] = (char)ch;
                len++;
            }
        }
        students[i].name[len] = '\0';

        /* Читаем оценку. */
        if (scanf("%d", &students[i].rate) != 1) {
            free(students);
            return 1;
        }

        /* Съедаем '\n' после оценки. */
        while ((ch = getchar()) != EOF && ch != '\n') {
        }
    }

    /*
     * Сортировка пузырьком по убыванию оценки.
     *
     * Внешний цикл: i — количество уже "всплывших" в конец элементов.
     * После каждого прохода наименьший элемент оказывается в конце
     * необработанной части, поэтому границу j можно уменьшать.
     *
     * Внутренний цикл: сравниваем соседние пары.
     * Если левый меньше правого — меняем местами.
     * Используется строгое <, а не <=, чтобы сортировка была устойчивой:
     * равные элементы не меняют относительный порядок.
     */
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (students[j].rate < students[j + 1].rate) {
                struct student tmp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tmp;
            }
        }
    }

    /*
     * Выводим отсортированный список.
     * Перевод строки печатаем перед каждым элементом, кроме первого,
     * чтобы в конце не было лишнего '\n'.
     */
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            putchar('\n');
        }
        printf("%s %d", students[i].name, students[i].rate);
    }

    /* Освобождаем память. */
    free(students);
    return 0;
}