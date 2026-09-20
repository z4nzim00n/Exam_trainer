#include <stdio.h>
#include <stdlib.h>

#define NAME_MAX_LEN 100

struct student {
    char name[NAME_MAX_LEN];
    int rate;
};

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        return 1;
    }

    /* Съедаем перевод строки после числа. */
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
    }

    struct student* students = malloc((size_t)n * sizeof(*students));
    if (students == NULL) {
        return 1;
    }

    long sum = 0;

    for (int i = 0; i < n; i++) {
        /* Читаем имя целиком со строки. */
        int len = 0;
        while ((ch = getchar()) != EOF && ch != '\n') {
            if (len < NAME_MAX_LEN - 1) {
                students[i].name[len] = (char)ch;
                len++;
            }
        }
        students[i].name[len] = '\0';

        if (scanf("%d", &students[i].rate) != 1) {
            free(students);
            return 1;
        }

        /* Съедаем перевод строки после оценки. */
        while ((ch = getchar()) != EOF && ch != '\n') {
        }

        sum += students[i].rate;
    }

    double avg = (double)sum / n;

    int first = 1;
    for (int i = 0; i < n; i++) {
        if ((double)students[i].rate > avg) {
            if (!first) {
                printf(", ");
            }
            printf("%s", students[i].name);
            first = 0;
        }
    }

    free(students);
    return 0;
}