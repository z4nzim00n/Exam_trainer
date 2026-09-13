#include <stdio.h>

int main(void) {
    int ch;
    int has_text = 0;
    int pending_space = 0;

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch == ' ') {
            if (has_text) {
                pending_space = 1;
            }
        } else {
            if (pending_space) {
                putchar(' ');
                pending_space = 0;
            }
            putchar(ch);
            has_text = 1;
        }
    }

    return 0;
}