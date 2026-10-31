#include <stdio.h>

typedef struct {
    char name[100];
    int rate;
} Student;

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 1) {
        printf("n/a");
        return 0;
    }

    Student students[n];

    for (int i = 0; i < n; i++) {
        if (scanf("%99s", students[i].name) != 1 || scanf("%d", &students[i].rate) != 1) {
            printf("n/a");
            return 0;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rate < students[j + 1].rate) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%s", students[i].name);
    }

    return 0;
}