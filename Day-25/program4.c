#include <stdio.h>
#include <string.h>
//program to sort words by length
void sort_words(char *words[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strlen(words[i]) > strlen(words[j])) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int main() {
    char *words[] = {"elephant", "cat", "banana", "dog", "hi"};
    int count = sizeof(words) / sizeof(words[0]);

    sort_words(words, count);

    for (int i = 0; i < count; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}
