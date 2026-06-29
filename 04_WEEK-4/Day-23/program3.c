#include <stdio.h>
#include <string.h>
//program to check anagram strings
int check_anagram(char str1[], char str2[]) {
    int count[256] = {0};
    int i = 0;

    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    while (str1[i] != '\0') {
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
        i++;
    }

    for (i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter first string: ");
    scanf("%99s", str1);

    printf("Enter second string: ");
    scanf("%99s", str2);

    if (check_anagram(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}
