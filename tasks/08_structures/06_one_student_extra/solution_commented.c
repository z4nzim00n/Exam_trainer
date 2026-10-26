/*
* EXAM_08_06. Один студент.
 *
 * Знакомство со структурой: описываем тип, создаём переменную,
 * читаем и печатаем её поля.
 */

#include <stdio.h>

/*
 * Описание структуры: «набор полей под одним именем».
 * typedef позволяет дальше писать просто Student.
 */
typedef struct {
    char name[100]; /* имя: 99 символов + '\0' */
    int rate;       /* оценка */
} Student;

int main(void) {
    /* Переменная типа Student. У неё есть два поля: name и rate. */
    Student student;

    /*
     * К полю обращаемся через точку: student.name, student.rate.
     * У name нет &: имя массива уже адрес. У rate & нужен.
     * %99s не даёт имени выйти за массив. scanf возвращает число прочитанных значений: нужно 2.
     */
    if (scanf("%99s %d", student.name, &student.rate) != 2) {
        printf("n/a");
        return 0;
    }

    printf("%s %d", student.name, student.rate);

    return 0;
}