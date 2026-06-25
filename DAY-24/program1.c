#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//program to check string rotation
int areRotations(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) return 0;
    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL) return 0;
    strcpy(temp, str1);
    strcat(temp, str1);
    char *ptr = strstr(temp, str2);
    free(temp);
    return (ptr != NULL);
}

int main() {
    char s1[] = "ABCD", s2[] = "CDAB";
    printf(areRotations(s1, s2) ? "Yes" : "No");
    return 0;
}
