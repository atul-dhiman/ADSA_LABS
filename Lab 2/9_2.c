#include <stdio.h>
int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Before swap: a = %d, b = %d\n", a, b);

    a = a ^ b;
    b = a ^ b;  // (a ^ b) ^ b = a
    a = a ^ b;  // (a ^ b) ^ a = b

    printf("After swap (XOR): a = %d, b = %d\n", a, b);
    return 0;
}
