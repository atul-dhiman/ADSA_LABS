#include <stdio.h>
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};
int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student s[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        printf("Roll number: ");
        scanf("%d", &s[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
    int maxIndex = 0;  
    for (i = 1; i < n; i++) {
        if (s[i].marks > s[maxIndex].marks) {
            maxIndex = i;
        }
    }
    printf("\nStudent with highest marks:\n");
    printf("Name: %s\n", s[maxIndex].name);
    printf("Roll Number: %d\n", s[maxIndex].rollNumber);
    printf("Marks: %.2f\n", s[maxIndex].marks);
    return 0;
}
