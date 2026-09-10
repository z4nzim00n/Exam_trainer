#include <stdio.h>

int main(void) {
    char text[102];
    int words = 0;

    /* 0 — вне слова, 1 — внутри уже посчитанного слова. */
    int in_word = 0;

    if (fgets(text, sizeof(text), stdin) != NULL) {
        for (int i = 0; text[i] != '\0' && text[i] != '\n'; i++) {
            if (text[i] == ' ') {
                /* Любой пробел переводит нас в состояние вне слова. */
                in_word = 0;
            } else if (!in_word) {
                /*
                 * Встретили непробельный символ вне слова:
                 * это начало нового слова.
                 */
                words++;
                in_word = 1;
            }

            /*
             * Если мы уже внутри слова, следующий непробельный
             * символ не увеличивает счётчик.
             */
        }
    }

    printf("%d", words);
    return 0;
}