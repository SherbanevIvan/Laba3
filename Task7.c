#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char name[50];
    int age;

} Student;

int main() {
    int N;
    printf("Введите количество студентов: ");
    scanf("%d", &N);

    Student *students_list = (Student*)malloc(N * sizeof(Student));
    if (students_list == NULL){ 
        return 1;
    }

    int maxage = 0;
    for (int i = 0; i < N; i++) {

        printf("\nИмя студента №%d: ", i+1);
        scanf("%49s", (char*)&students_list[i].name);

        printf("Возраст: ");

        scanf("%d", &students_list[i].age);
        printf("\n");

        if (students_list[i].age > students_list[maxage].age){ 

            maxage = i;

        }

    }

    printf("\nСтуденты:\n");
    for (int i = 0; i < N; i++) {
        printf("%s, %d лет\n", students_list[i].name, students_list[i].age);
    }

    printf("\nСамый старший: %s (%d лет)\n", 
           students_list[maxage].name, students_list[maxage].age);

    free(students_list);

}