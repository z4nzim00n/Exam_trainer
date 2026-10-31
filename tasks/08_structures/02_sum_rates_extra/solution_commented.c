/*
 * EXAM_08_02. Сумма оценок.
 *
 * Следующий шаг после одного студента: массив структур.
 * Читаем n студентов в цикле и складываем оценки.
 */

#include <stdio.h>

typedef struct {
    char name[100]; /* 99 символов + '\0' */
    int rate;
} Student;

int main(void) {
    int n;

    /* Не прочиталось число или оно меньше 1 — ошибка. */
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
        return 0;
    }

    /* Массив из n студентов: students[0], students[1], ... */
    Student students[n];
    long sum = 0; /* сумма оценок */

    for (int i = 0; i < n; i++) {
        /*
         * students[i] — один студент, дальше точка и поле.
         * У name нет &, у rate есть. scanf должен вернуть 2.
         */
        if (scanf("%99s %d", students[i].name, &students[i].rate) != 2) {
            printf("n/a");
            return 0;
        }
        sum += students[i].rate;
    }

    printf("%ld", sum);

    return 0;
}