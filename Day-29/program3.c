#include <stdio.h>
#include <string.h>

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void read_string(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    char str1[200];
    char str2[100];
    int choice;

    do {
        printf("\n--- STRING OPERATIONS MENU ---\n");
        printf("1. Find String Length\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Strings\n");
        printf("4. Compare Strings\n");
        printf("5. Reverse String\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_buffer();
            continue;
        }
        clear_buffer();

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                read_string(str1, sizeof(str1));
                printf("Length of the string: %lu\n", strlen(str1));
                break;

            case 2:
                printf("Enter the source string: ");
                read_string(str1, sizeof(str1));
                strcpy(str2, str1);
                printf("Destination string after copy: %s\n", str2);
                break;

            case 3:
                printf("Enter the first string: ");
                read_string(str1, sizeof(str1));
                printf("Enter the second string: ");
                read_string(str2, sizeof(str2));
                
                if (strlen(str1) + strlen(str2) < sizeof(str1)) {
                    strcat(str1, str2);
                    printf("Concatenated string: %s\n", str1);
                } else {
                    printf("Error: Buffer overflow danger. Cannot concatenate.\n");
                }
                break;

            case 4:
                printf("Enter the first string: ");
                read_string(str1, sizeof(str1));
                printf("Enter the second string: ");
                read_string(str2, sizeof(str2));
                
                int cmp = strcmp(str1, str2);
                if (cmp == 0) {
                    printf("Strings are equal.\n");
                } else if (cmp > 0) {
                    printf("First string is lexicographically greater.\n");
                } else {
                    printf("Second string is lexicographically greater.\n");
                }
                break;

            case 5:
                printf("Enter a string to reverse: ");
                read_string(str1, sizeof(str1));
                int len = strlen(str1);
                for (int i = 0; i < len / 2; i++) {
                    char temp = str1[i];
                    str1[i] = str1[len - 1 - i];
                    str1[len - 1 - i] = temp;
                }
                printf("Reversed string: %s\n", str1);
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please select an option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
