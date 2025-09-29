#include <stdio.h>
struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct Employee emp[n]; 
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf(" %[^\n]", emp[i].name); 
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
    printf("\nEmployee Details:\n");
    printf("---------------------------------------------------\n");
    printf("%-5s %-20s %-10s\n", "ID", "Name", "Salary");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-20s %-10.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    }
    return 0;
}
