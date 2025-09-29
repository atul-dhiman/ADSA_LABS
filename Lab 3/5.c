#include <stdio.h>
#include <string.h>
struct Employee {
    int id;
    char name[50];
    float salary;
    char department[50];
};
int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employee employees[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf(" %[^\n]", employees[i].name); 
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("Department: ");
        scanf(" %[^\n]", employees[i].department); 
    }
    for (int i = 0; i < n; i++) {
        if (strcmp(employees[i].department, "IT") == 0) {
            employees[i].salary *= 1.10; 
        }
    }
    printf("\nUpdated Employee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("Department: %s\n", employees[i].department);
    }

    return 0;
}
