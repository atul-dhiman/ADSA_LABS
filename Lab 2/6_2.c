#include <stdio.h>
int main() {
    int n;
    printf("Enter number of customers: ");
    scanf("%d", &n);

    int ids[n + 1]; // +1 for sentinel
    printf("Enter customer IDs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ids[i]);
    }

    int key;
    printf("Enter customer ID to search: ");
    scanf("%d", &key);

    ids[n] = key;

    int i = 0;
    while (ids[i] != key) {
        i++;
    }
    if (i < n)
        printf("Customer ID %d found at position %d (index %d)\n", key, i + 1, i);
    else
        printf("Customer ID %d not found\n", key);
    return 0;
}
