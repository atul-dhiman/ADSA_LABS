#include <stdio.h>
struct Date {
    int day;
    int month;
    int year;
};
struct Student {
    char name[50];
    int rollNumber;
    struct Date dob; 
};
int main() {
    struct Student s;
    printf("Enter student name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter roll number: ");
    scanf("%d", &s.rollNumber);
    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d", &s.dob.day, &s.dob.month, &s.dob.year);
    printf("\nStudent Details:\n");
    printf("Name: %s\n", s.name);
    printf("Roll Number: %d\n", s.rollNumber);
    printf("Date of Birth: %02d-%02d-%04d\n",
           s.dob.day, s.dob.month, s.dob.year);
    return 0;
}
