#include <stdio.h>
//program to covert lowercase into uppercase
int main() {
    char lower;
    char upper;

    printf("Enter a lowercase letter: ");
    scanf("%c", &lower);

    upper = lower - 32;

    printf("Uppercase letter: %c\n", upper);

    return 0;
}

