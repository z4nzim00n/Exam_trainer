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
    long sum = 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%99s", students[i].name) != 1 || scanf("%d", &students[i].rate) != 1) {
            printf("n/a");
            return 0;
        }
        sum += students[i].rate;
    }

    double avg = (double)sum / n;
    int first = 1;

    for (int i = 0; i < n; i++) {
        if (students[i].rate > avg) {
            if (!first) {
                printf(", ");
            }
            printf("%s", students[i].name);
            first = 0;
        }
    }

    return 0;
}