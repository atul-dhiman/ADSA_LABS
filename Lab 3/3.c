#include <stdio.h>
void rotateclockwise(int arr[], int n, int k) {
    if (k == 0) 
        return;
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;

    rotateclockwise(arr, n, k - 1);
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int k;
    printf("How many positions do you want to shift? ");
    scanf("%d", &k);
    rotateclockwise(arr, n, k);
    printf("Array after rotating %d positions clockwise:\n", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
