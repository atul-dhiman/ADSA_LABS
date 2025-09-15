#include <stdio.h>
int main() {
    int n;
    printf("Enter number of customers: ");
    scanf("%d", &n);
    int ids[n];
    printf("Enter customer IDs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ids[i]);
    }
    int key;
    printf("Enter customer ID to search: ");
    scanf("%d", &key);
    int found = -1; 
    for (int i = 0; i < n; i++) {
        if (ids[i] == key) {
            found = i;
            break;
        }
    }
    if (found != -1)
        printf("Customer ID %d found at position %d (index %d)\n", key, found + 1, found);
    else
        printf("Customer ID %d not found\n", key);

    return 0;
}
