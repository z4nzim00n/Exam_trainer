#include <stdio.h>

int main(void) {
    char text[102];
    int length = 0;

    /* Считаем строку палиндромом, пока не найдём несовпадение. */
    int palindrome = 1;

    if (fgets(text, sizeof(text), stdin) != NULL) {
        /* Не включаем в длину перевод строки и терминатор. */
        while (text[length] != '\0' && text[length] != '\n') {
            length++;
        }
    }

    /* Проверяем пары симметричных символов до середины строки. */
    for (int i = 0; i < length / 2; i++) {
        if (text[i] != text[length - 1 - i]) {
            /* Одного несовпадения достаточно для отрицательного ответа. */
            palindrome = 0;
            break;
        }
    }

    /* Для пустой и односимвольной строки результат остаётся равным 1. */
    printf("%d", palindrome);
    return 0;
}