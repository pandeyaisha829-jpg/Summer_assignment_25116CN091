#include <stdio.h>
#include <string.h>
//program to reverse a string
void reverseString(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char myString[] = "Hello, World!";
    
    printf("Original: %s\n", myString);
    reverseString(myString);
    printf("Reversed: %s\n", myString);
    
    return 0;
}
