#include <stdio.h>
void printNumbers(int current, int n) {
    if (current > n) 
        return;
    printf("%d ", current);
    printNumbers(current + 1, n);
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("First %d natural numbers (recursion):\n", n);
    printNumbers(1, n); 
    printf("\n");
    return 0;
}
