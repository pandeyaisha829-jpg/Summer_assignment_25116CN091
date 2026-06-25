#include <stdio.h>
#include <string.h>
#include <ctype.h>
//program to find longest word
int main() {
    char sentence[1000];
    char longest[256] = "";
    char current[256];
    int max_len = 0;
    int cur_len = 0;
    int i = 0;

    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        return 1;
    }

    while (sentence[i] != '\0') {
        if (isalnum((unsigned char)sentence[i])) {
            if (cur_len < 255) {
                current[cur_len] = sentence[i];
                cur_len++;
            }
        } else {
            if (cur_len > 0) {
                current[cur_len] = '\0';
                if (cur_len > max_len) {
                    max_len = cur_len;
                    strcpy(longest, current);
                }
                cur_len = 0;
            }
        }
        i++;
    }

    if (cur_len > max_len) {
        current[cur_len] = '\0';
        max_len = cur_len;
        strcpy(longest, current);
    }

    if (max_len > 0) {
        printf("Longest word: %s\n", longest);
        printf("Length: %d\n", max_len);
    } else {
        printf("No words found.\n");
    }

    return 0;
}
