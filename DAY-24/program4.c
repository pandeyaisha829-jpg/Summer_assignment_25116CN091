#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//program to remove duplicate character
void removeDuplicates(char *str) {
    bool seen[256] = {false};
    int writeIndex = 0;
    
    for (int readIndex = 0; str[readIndex] != '\0'; readIndex++) {
        unsigned char ch = str[readIndex];
        if (!seen[ch]) {
            seen[ch] = true;
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
    }
    str[writeIndex] = '\0';
}

int main() {
    char testStr[] = "programming";
    
    printf("Original: %s\n", testStr);
    removeDuplicates(testStr);
    printf("Modified: %s\n", testStr);
    
    return 0;
}
