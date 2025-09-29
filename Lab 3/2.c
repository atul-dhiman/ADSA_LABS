#include <stdio.h>
void subarraySum(int arr[], int n, int target) {
    for (int s = 0; s < n; s++) {
        int curr = 0;
        for (int e = s; e < n; e++) {
            curr += arr[e];
            if (curr == target) {
                printf("%d %d\n", s + 1, e + 1);
                return; 
            }
        }
    }
    printf("-1\n");
}
int main() {
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    subarraySum(arr, n, target);
    return 0;
}
// int main() {
//     int n, target;
//     printf("Enter number of elements: ");
//     scanf("%d", &n);
//     int arr[n]; 
//     printf("Enter %d integers:\n", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }
//     printf("Enter target sum: ");
//     scanf("%d", &target);
//     subarraySum(arr, n, target);
//     return 0;
// }
