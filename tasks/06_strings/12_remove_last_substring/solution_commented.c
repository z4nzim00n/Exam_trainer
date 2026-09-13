#include <stdio.h>

/*
 * Читаем одну строку до '\n' или EOF.
 * Записываем не больше size - 1 символов, чтобы оставить место под '\0'.
 * Символы сверх лимита просто игнорируем: по условию длина не превышает буфер.
 */
static int read_line(char str[], int size) {
    int length = 0;
    int ch;

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (length < size - 1) {
            str[length] = (char)ch;
            length++;
        }
    }

    str[length] = '\0';
    return length;
}

int main(void) {
    /* 200 символов + '\0' с запасом. */
    char text[202];
    char pattern[102];

    int text_length = read_line(text, sizeof(text));
    int pattern_length = read_line(pattern, sizeof(pattern));

    /* Позиция последнего найденного вхождения. -1 означает "не найдено". */
    int last_match = -1;

    /*
     * Ищем все вхождения и запоминаем позицию последнего.
     * Пустая подстрока или подстрока длиннее текста — искать нечего.
     */
    if (pattern_length > 0 && pattern_length <= text_length) {
        for (int i = 0; i <= text_length - pattern_length; i++) {
            int matched = 1;

            /* Сравниваем pattern_length символов начиная с позиции i. */
            for (int j = 0; j < pattern_length; j++) {
                if (text[i + j] != pattern[j]) {
                    matched = 0;
                    break;
                }
            }

            if (matched) {
                last_match = i;
            }
        }
    }

    /*
     * Выводим текст, пропуская символы найденного вхождения.
     * Если ничего не нашли, last_match == -1 и условие пропуска не сработает.
     */
    for (int i = 0; i < text_length; i++) {
        if (last_match != -1
            && i >= last_match
            && i < last_match + pattern_length) {
            continue;
            }
        putchar(text[i]);
    }

    /* Перевод строки в конце не добавляем. */
    return 0;
}