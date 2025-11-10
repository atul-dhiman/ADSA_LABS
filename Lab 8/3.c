#include <stdio.h>
void partialSelectionSort(int arr[], int n, int k) {
    int i, j, minIndex, temp;
    for (i = 0; i < k; i++) {
        minIndex = i;
        // Find the smallest element in the unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap it with the element at position i
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        // Print progress
        printf("After iteration %d: ", i + 1);
        for (j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}
int main() {
    int arr[100], n, k, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k (how many smallest elements to sort): ");
    scanf("%d", &k);

    if (k > n) {
        printf("k cannot be greater than number of elements.\n");
        return 0;
    }

    printf("\nPartial Selection Sort Progress:\n");
    partialSelectionSort(arr, n, k);

    printf("\nArray after partial sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
