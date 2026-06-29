#include <stdio.h>
#include <string.h>
//program to remove duplicate character
void removeDuplicates(char *str) {
    int hash[256] = {0};
    int currentIndex = 0;
    int writeIndex = 0;

    while (str[currentIndex] != '\0') {
        unsigned char character = str[currentIndex];
        if (hash[character] == 0) {
            hash[character] = 1;
            str[writeIndex] = str[currentIndex];
            writeIndex++;
        }
        currentIndex++;
    }
    str[writeIndex] = '\0';
}

int main() {
    char str[100];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\n")] = '\0';
        removeDuplicates(str);
        printf("Result: %s\n", str);
    }

    return 0;
}
