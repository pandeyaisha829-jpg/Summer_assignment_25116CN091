#include <stdio.h>
//program to remove spaces from string
void removeSpaces(char *str) {
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char text[] = "C  pro gram  m ing";
    removeSpaces(text);
    printf("%s\n", text);
    return 0;
}
