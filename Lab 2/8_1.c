#include <stdio.h>
#include <string.h>
#include <ctype.h> 
int main() {
    char comment[500];
    printf("Enter user comment: ");
    fgets(comment, sizeof(comment), stdin);  
    int count = 0;
    for (int i = 0; i < strlen(comment); i++) {
        char c = tolower(comment[i]);  
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    printf("Number of vowels (simple check): %d\n", count);
    return 0;
}
