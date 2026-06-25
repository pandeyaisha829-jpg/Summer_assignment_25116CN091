#include <stdio.h>
#include <string.h>
//program to compress a string
void compressString(const char *src, char *dst) {
    int i = 0;
    int j = 0;
    int len = strlen(src);

    while (i < len) {
        dst[j++] = src[i];
        int count = 1;
        
        while (i + 1 < len && src[i] == src[i + 1]) {
            count++;
            i++;
        }
        
        j += sprintf(&dst[j], "%d", count);
        i++;
    }
    dst[j] = '\0';
}

int main() {
    char input[] = "aaabbcccddddd";
    char compressed[100];

    compressString(input, compressed);

    printf("Original: %s\n", input);
    printf("Compressed: %s\n", compressed);

    return 0;
}
