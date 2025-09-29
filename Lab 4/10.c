#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    char name[50];
    int roll;
    float marks;
};
int main() {
    struct Student *students = NULL;
    int n, new_n;
    printf("Enter initial number of students: ");
    scanf("%d", &n);
    students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Roll number: ");
        scanf("%d", &students[i].roll);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
    printf("\nEnter new total number of students (must be > %d): ", n);
    scanf("%d", &new_n);
    if (new_n <= n) {
        printf("New size must be greater than old size.\n");
        free(students);
        return 1;
    }
    struct Student *temp = realloc(students, new_n * sizeof(struct Student));
    if (temp == NULL) {
        printf("Memory reallocation failed\n");
        free(students);
        return 1;
    }
    students = temp; 
    for (int i = n; i < new_n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Roll number: ");
        scanf("%d", &students[i].roll);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
    printf("\nAll Students:\n");
    printf("--------------------------------------------------\n");
    printf("%-5s %-20s %-10s\n", "Roll", "Name", "Marks");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < new_n; i++) {
        printf("%-5d %-20s %-10.2f\n",
               students[i].roll, students[i].name, students[i].marks);
    }
    free(students);
    return 0;
}
