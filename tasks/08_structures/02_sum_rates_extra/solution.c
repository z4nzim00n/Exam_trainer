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
        if (scanf("%99s %d", students[i].name, &students[i].rate) != 2) {
            printf("n/a");
            return 0;
        }
        sum += students[i].rate;
    }

    printf("%ld", sum);

    return 0;
}