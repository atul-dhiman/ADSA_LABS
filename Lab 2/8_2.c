#include <stdio.h>
#include <string.h>
int main() {
    char comment[500];
    printf("Enter user comment: ");
    fgets(comment, sizeof(comment), stdin);
    int isVowel[256] = {0};
    isVowel['a'] = 1; isVowel['e'] = 1; isVowel['i'] = 1; isVowel['o'] = 1; isVowel['u'] = 1;
    isVowel['A'] = 1; isVowel['E'] = 1; isVowel['I'] = 1; isVowel['O'] = 1; isVowel['U'] = 1;
    int count = 0;
    for (int i = 0; i < strlen(comment); i++) {
        unsigned char c = comment[i];  
        if (isVowel[c]) {
            count++;
        }
    }
    printf("Number of vowels (lookup table): %d\n", count);
    return 0;
}
