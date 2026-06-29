#include <stdio.h>
#include <string.h>
//program to check palindrome string
int main() {
    char str[100];
    int left = 0;
    int right;
    int isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
