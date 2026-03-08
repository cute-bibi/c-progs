#include <stdio.h>
struct Student {
    int roll;
    char name[50];
    int age;
    float marks;
};
int main(void) {
    struct Student s[100];
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);
        printf("Enter name: ");
        scanf("%s", s[i].name);
        printf("Enter age: ");
        scanf("%d", &s[i].age);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }
    printf("\nStored Students Information:\n");
    for (i = 0; i < n; i++) {
        printf("Roll: %d, Name: %s, Age: %d, Marks: %.2f\n",
               s[i].roll, s[i].name, s[i].age, s[i].marks);
    }
    return 0;
}
