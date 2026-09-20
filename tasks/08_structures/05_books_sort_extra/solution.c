#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_LEN 100

struct book {
    char name[NAME_MAX_LEN];
    int year;
};

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        return 1;
    }

    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
    }

    struct book* books = malloc((size_t)n * sizeof(*books));
    if (books == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int len = 0;
        while ((ch = getchar()) != EOF && ch != '\n') {
            if (len < NAME_MAX_LEN - 1) {
                books[i].name[len] = (char)ch;
                len++;
            }
        }
        books[i].name[len] = '\0';

        if (scanf("%d", &books[i].year) != 1) {
            free(books);
            return 1;
        }

        while ((ch = getchar()) != EOF && ch != '\n') {
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            int swap = 0;

            if (books[j].year > books[j + 1].year) {
                swap = 1;
            } else if (books[j].year == books[j + 1].year) {
                if (strcmp(books[j].name, books[j + 1].name) > 0) {
                    swap = 1;
                }
            }

            if (swap) {
                struct book tmp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            putchar('\n');
        }
        printf("%d %s", books[i].year, books[i].name);
    }

    free(books);
    return 0;
}