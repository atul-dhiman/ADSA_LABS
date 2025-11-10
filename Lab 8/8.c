#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure to store subarray indices
struct Stack {
    int top;
    int left[MAX];
    int mid[MAX];
    int right[MAX];
};

// Push operation
void push(struct Stack* s, int l, int m, int r) {
    s->top++;
    s->left[s->top] = l;
    s->mid[s->top] = m;
    s->right[s->top] = r;
}

// Pop operation
void pop(struct Stack* s, int* l, int* m, int* r) {
    *l = s->left[s->top];
    *m = s->mid[s->top];
    *r = s->right[s->top];
    s->top--;
}

// Merge two sorted subarrays
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Iterative merge simulation using stack
void mergeSimulation(int arr[], int n) {
    struct Stack s;
    s.top = -1;

    int curr_size;  // Current size of subarrays to merge
    int left_start; // Starting index of left subarray

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2 * curr_size - 1 < n - 1) ? 
                            (left_start + 2 * curr_size - 1) : (n - 1);

            // Push merge operation onto stack
            push(&s, left_start, mid, right_end);
        }
    }

    // Pop and perform merges (simulating recursion unwind)
    while (s.top != -1) {
        int l, m, r;
        pop(&s, &l, &m, &r);
        if (m < r)
            merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSimulation(arr, n);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
