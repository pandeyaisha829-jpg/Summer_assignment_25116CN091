#include <stdio.h>
#include <string.h>
//program to find common character in string
void findCommonChars(char str1[], char str2[]) {
    int freq1[256] = {0};
    int freq2[256] = {0};
    int i;

    for (i = 0; str1[i] != '\0'; i++) {
        freq1[(unsigned char)str1[i]] = 1;
    }

    for (i = 0; str2[i] != '\0'; i++) {
        freq2[(unsigned char)str2[i]] = 1;
    }

    printf("Common characters: ");
    int found = 0;
    for (i = 0; i < 256; i++) {
        if (freq1[i] && freq2[i]) {
            printf("%c ", i);
            found = 1;
        }
    }
    
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    findCommonChars(str1, str2);

    return 0;
}
