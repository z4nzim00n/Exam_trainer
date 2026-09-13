#include <stdio.h>

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
    char text[202];
    char pattern[102];

    int text_length = read_line(text, sizeof(text));
    int pattern_length = read_line(pattern, sizeof(pattern));

    int last_match = -1;

    if (pattern_length > 0 && pattern_length <= text_length) {
        for (int i = 0; i <= text_length - pattern_length; i++) {
            int matched = 1;

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

    for (int i = 0; i < text_length; i++) {
        if (last_match != -1
            && i >= last_match
            && i < last_match + pattern_length) {
            continue;
            }
        putchar(text[i]);
    }

    return 0;
}