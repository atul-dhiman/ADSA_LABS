#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    unsigned long long fact = 1; 
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("Factorial of %d (Iterative): %llu\n", n, fact);
    return 0;
}
