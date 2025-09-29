#include <stdio.h>
#include <string.h>
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};
int main() {
    struct Student s1, s2;
    printf("Enter first student details:\n");
    printf("Name: ");
    scanf(" %[^\n]", s1.name);
    printf("Roll number: ");
    scanf("%d", &s1.rollNumber);
    printf("Marks: ");
    scanf("%f", &s1.marks);
    printf("\nEnter second student details:\n");
    printf("Name: ");
    scanf(" %[^\n]", s2.name);
    printf("Roll number: ");
    scanf("%d", &s2.rollNumber);
    printf("Marks: ");
    scanf("%f", &s2.marks);
    if ( (s1.rollNumber == s2.rollNumber) &&
         (s1.marks == s2.marks) &&
         (strcmp(s1.name, s2.name) == 0) ) {
        printf("\nBoth students are the same.\n");
    } else {
        printf("\nStudents are different.\n");
    }
    return 0;
}
