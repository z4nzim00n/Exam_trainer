#include <stdio.h>

int main(void) {
    char text[102];
    int words = 0;
    int in_word = 0;

    if (fgets(text, sizeof(text), stdin) != NULL) {
        for (int i = 0; text[i] != '\0' && text[i] != '\n'; i++) {
            if (text[i] == ' ') {
                in_word = 0;
            } else if (!in_word) {
                words++;
                in_word = 1;
            }
        }
    }

    printf("%d", words);
    return 0;
}