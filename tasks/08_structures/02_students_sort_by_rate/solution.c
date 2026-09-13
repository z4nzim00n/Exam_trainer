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

    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
    }

    struct student *students = malloc((size_t)n * sizeof(*students));
    if (students == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
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

        while ((ch = getchar()) != EOF && ch != '\n') {
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (students[j].rate < students[j + 1].rate) {
                struct student tmp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            putchar('\n');
        }
        printf("%s %d", students[i].name, students[i].rate);
    }

    free(students);
    return 0;
}