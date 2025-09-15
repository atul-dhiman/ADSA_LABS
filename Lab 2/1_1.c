#include <stdio.h>
int main() {
    int n, i;
    printf("Enter number of days: ");
    scanf("%d", &n);
    int sales[n];
    printf("Enter daily sales:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }
    int total = 0;
    for (i = 0; i < n; i++) {
        total += sales[i];
    }
    printf("Total sales (Iterative): %d\n", total);
    return 0;
}
