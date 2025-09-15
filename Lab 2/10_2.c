#include <stdio.h>
int main() {
    long long num;
    printf("Enter ID number: ");
    scanf("%lld", &num);
    long long original = num;
    long long reversed = 0;
    while (num > 0) {
        int digit = num % 10;            
        reversed = reversed * 10 + digit; 
        num = num / 10;                   
    }
    if (original == reversed)
        printf("The ID %lld is a palindrome (math check)\n", original);
    else
        printf("The ID %lld is NOT a palindrome (math check)\n", original);
    return 0;
}
