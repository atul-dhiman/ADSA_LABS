#include <stdio.h>
int main() {
    int n, i;
    printf("Enter number of days: ");
    scanf("%d", &n);
    int temp[n];
    printf("Enter temperature readings:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &temp[i]);
    }
    int max = temp[0];
    for (i = 1; i < n; i++) {
        if (temp[i] > max) {
            max = temp[i];
        }
    }
    printf("Maximum temperature (Linear Scan): %d\n", max);
    return 0;
}
