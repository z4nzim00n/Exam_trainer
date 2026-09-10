#include <stdio.h>

int main(void) {
    char text[102];
    int length = 0;

    if (fgets(text, sizeof(text), stdin) != NULL) {
        /* Находим длину текста без '\n' и '\0'. */
        while (text[length] != '\0' && text[length] != '\n') {
            length++;
        }
    }

    /*
     * Последний символ находится на позиции length - 1.
     * Сначала уменьшаем индекс, затем выводим символ.
     */
    while (length > 0) {
        length--;
        putchar(text[length]);
    }

    /*
     * Для пустой строки length равно 0,
     * поэтому обращений к массиву не будет.
     */
    return 0;
}