#include <stdio.h>

int main(void) {
    char text[102];
    int length = 0;

    if (fgets(text, sizeof(text), stdin) != NULL) {
        while (text[length] != '\0' && text[length] != '\n') {
            length++;
        }
    }

    while (length > 0) {
        length--;
        putchar(text[length]);
    }

    return 0;
}