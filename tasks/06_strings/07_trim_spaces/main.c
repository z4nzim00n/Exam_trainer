#include <stdio.h>

int main(void) {
    int c;
    int needSpace = 0;
    int haveWords = 0;

    while ((c = getchar()) != EOF && c != '\n' && c != '\0') {
        if (c == ' ' && haveWords == 1) {
            needSpace = 1;
        }

        if (c != ' ') {
            haveWords = 1;
            if (needSpace) {
                putchar(' ');
                needSpace = 0;
            }
            putchar(c);
        }
    }
    return 0;
}