#include <stdio.h>

int main(void) {
    /*
     * 100 символов текста + возможный '\n' + завершающий '\0'.
     */
    char text[102];
    int length = 0;

    /* fgets читает строку вместе с пробелами. */
    if (fgets(text, sizeof(text), stdin) != NULL) {
        /*
         * Считаем только символы текста.
         * Перевод строки и нулевой терминатор не учитываем.
         */
        while (text[length] != '\0' && text[length] != '\n') {
            length++;
        }
    }

    /* При пустом вводе length остаётся равным 0. */
    printf("%d", length);
    return 0;
}