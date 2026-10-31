/*
 * Звёзды Голливуда.
 *
 * Читаем людей (имя, фамилия, рост), затем искомое имя.
 * Выводим фамилии всех с этим именем, двоеточие и их средний рост.
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

/* Структура: имя, фамилия, рост. */
typedef struct {
    char name[100];    /* 99 символов + '\0' */
    char surname[100]; /* 99 символов + '\0' */
    int height;
} Person;

int main(void) {
    int n;

    /* Не прочиталось число или оно меньше 1 — ошибка. */
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
        return 0;
    }

    Person people[n];

    for (int i = 0; i < n; i++) {
        /*
         * Один scanf читает три значения и возвращает, сколько прочитал.
         * У name и surname нет &: имя массива уже адрес. У height & нужен.
         */
        if (scanf("%99s %99s %d", people[i].name, people[i].surname, &people[i].height) != 3) {
            printf("n/a");
            return 0;
        }
    }

    /* Последнее, что вводят, — имя для поиска. */
    char search[100];
    if (scanf("%99s", search) != 1) {
        printf("n/a");
        return 0;
    }

    int count = 0; /* сколько людей с таким именем */
    long sum = 0;  /* сумма их ростов */

    /* Проход 1: считаем совпавших и сумму ростов. */
    for (int i = 0; i < n; i++) {
        /* strcmp возвращает 0, если строки равны. Оператор == сравнил бы адреса. */
        if (strcmp(search, people[i].name) == 0) {
            count++;
            sum += people[i].height;
        }
    }

    int first = 1; /* 1, пока ни одна фамилия не напечатана */

    /* Проход 2: печатаем фамилии. ", " ставим ПЕРЕД фамилией, кроме первой. */
    for (int i = 0; i < n; i++) {
        if (strcmp(search, people[i].name) == 0) {
            if (!first) {
                printf(", ");
            }
            printf("%s", people[i].surname);
            first = 0;
        }
    }

    /*
     * Если совпавшие есть, печатаем ": " и средний рост.
     * (double) нужен, чтобы деление не было целочисленным.
     * round делает математическое округление (182.5 -> 183). Один %.0f округлил бы 182.5 до 182.
     * Если совпавших нет, цикл выше ничего не напечатал, остаётся только n/a.
     */
    if (count > 0) {
        printf(": %.0f", round((double)sum / count));
    } else {
        printf("n/a");
    }

    return 0;
}