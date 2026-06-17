#include <stdio.h>
//move zeroes to end,
void moveZeroesToEnd(int arr[], int size) {
    int count = 0; 
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[count] = arr[i];
            count++;
        }
    }

    while (count < size) {
        arr[count] = 0;
        count++;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 0, 3, 0, 12, 0, 5, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, size);

    // Perform the in-place manipulation
    moveZeroesToEnd(arr, size);

    printf("\nArray after moving zeroes to the end:\n");
    printArray(arr, size);

    return 0;
}
