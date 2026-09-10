#include <stdio.h>

static void read_line(char str[], int size) {
    if (fgets(str, size, stdin) == NULL) {
        str[0] = '\0';
    }

    int i = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        i++;
    }

    str[i] = '\0';
}

int main(void) {
    char first[102];
    char second[102];

    read_line(first, sizeof(first));
    read_line(second, sizeof(second));

    int i = 0;

    while (first[i] != '\0' && first[i] == second[i]) {
        i++;
    }

    printf("%d", first[i] == second[i]);

    return 0;
}