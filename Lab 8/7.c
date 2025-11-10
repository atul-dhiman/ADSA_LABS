#include <stdio.h>

// ---------- Function to perform selection sort on a subarray ----------
void selectionSort(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        int minIndex = i;
        for (int j = i + 1; j <= end; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// ---------- Function to merge two sorted subarrays ----------
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// ---------- Hybrid Sort Function ----------
void hybridSort(int arr[], int n, int chunkSize) {
    // Step 1: Divide array into chunks and sort each using selection sort
    for (int i = 0; i < n; i += chunkSize) {
        int end = (i + chunkSize - 1 < n) ? (i + chunkSize - 1) : (n - 1);
        selectionSort(arr, i, end);
    }

    // Step 2: Merge sorted chunks progressively
    int currentSize = chunkSize;
    while (currentSize < n) {
        for (int left = 0; left < n; left += 2 * currentSize) {
            int mid = left + currentSize - 1;
            int right = (left + 2 * currentSize - 1 < n) ? (left + 2 * currentSize - 1) : (n - 1);

            if (mid < right)
                merge(arr, left, mid, right);
        }
        currentSize *= 2;
    }
}

// ---------- Main Function ----------
int main() {
    int n, chunkSize;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter chunk size: ");
    scanf("%d", &chunkSize);

    printf("\nOriginal array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    hybridSort(arr, n, chunkSize);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
