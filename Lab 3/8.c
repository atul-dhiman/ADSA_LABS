#include <stdio.h>
int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    printf("Enter target sum: ");
    scanf("%d", &target);
    int found = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("Indices: %d, %d\n", i, j);
                found = 1;
                break;
            }
        }
        if (found) break; 
    }
    if (!found) {
        printf("No solution found.\n");
    }
    return 0;
}
