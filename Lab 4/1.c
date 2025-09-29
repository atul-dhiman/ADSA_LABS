#include <stdio.h>
struct Complex {
    float real;
    float imag;
};
void swap(struct Complex *c1, struct Complex *c2) {
    struct Complex temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}
int main() {
    struct Complex num1, num2;
    printf("Enter first complex number (real imag): ");
    scanf("%f %f", &num1.real, &num1.imag);
    printf("Enter second complex number (real imag): ");
    scanf("%f %f", &num2.real, &num2.imag);
    printf("\nBefore swapping:\n");
    printf("Number 1 = %.2f + %.2fi\n", num1.real, num1.imag);
    printf("Number 2 = %.2f + %.2fi\n", num2.real, num2.imag);
    swap(&num1, &num2);
    printf("\nAfter swapping:\n");
    printf("Number 1 = %.2f + %.2fi\n", num1.real, num1.imag);
    printf("Number 2 = %.2f + %.2fi\n", num2.real, num2.imag);
    return 0;
}
