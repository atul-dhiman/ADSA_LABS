#include <stdio.h>
int sum_recursive(int arr[], int n) {
    if (n == 0)
        return 0;
    else
        return arr[n - 1] + sum_recursive(arr, n - 1);
}
int main() {
    int n, i;
    printf("Enter number of days: ");
    scanf("%d", &n);

    int sales[n];
    printf("Enter daily sales:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }
    int total = sum_recursive(sales, n);
    printf("Total sales (Recursive): %d\n", total);
    return 0;
}
