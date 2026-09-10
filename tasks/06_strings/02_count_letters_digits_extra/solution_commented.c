#include <stdio.h>

int main(void) {
    /* Место для 100 символов, перевода строки и '\0'. */
    char text[102];
    int letters = 0;
    int digits = 0;

    if (fgets(text, sizeof(text), stdin) != NULL) {
        /* Завершающие '\n' и '\0' не обрабатываем. */
        for (int i = 0; text[i] != '\0' && text[i] != '\n'; i++) {
            char ch = text[i];

            /* Буква может принадлежать одному из двух диапазонов. */
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                letters++;
            } else if (ch >= '0' && ch <= '9') {
                /* Каждая цифра считается отдельным символом. */
                digits++;
            }

            /* Пробелы и знаки препинания не меняют счётчики. */
        }
    }

    /* Ровно один пробел между двумя числами. */
    printf("%d %d", letters, digits);
    return 0;
}