#include <stdio.h>

typedef struct {
    char name[100];
    int rate;
} Student;

int main(void) {
    Student student;

    if (scanf("%99s %d", student.name, &student.rate) != 2) {
        printf("n/a");
        return 0;
    }

    printf("%s %d", student.name, student.rate);

    return 0;
}