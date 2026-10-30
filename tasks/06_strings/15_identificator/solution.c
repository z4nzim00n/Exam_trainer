#include <stdio.h>

int main(void) {
    char str[102];
    int is_identifier = 0;

    if (fgets(str, sizeof str, stdin) != NULL && str[0] != '\n') {
        is_identifier = 1;

        for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
            int letter =
                (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z');
            int number = str[i] >= '0' && str[i] <= '9';
            int under = str[i] == '_';

            if (!letter && !under && !(number && i != 0)) {
                is_identifier = 0;
                break;
            }
        }
    }

    printf("%s", is_identifier ? "Yes" : "No");
    return 0;
}