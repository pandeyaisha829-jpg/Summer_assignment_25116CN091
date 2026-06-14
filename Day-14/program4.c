#include <stdio.h>
//program for finding duplicates in an array
void findDuplicatesBruteForce(int arr[], int size) {
    int foundDuplicate = 0;

    printf("Duplicate elements are: ");
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                foundDuplicate = 1;
                break; 
            }
        }
    }

    if (!foundDuplicate) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 4, 5, 2, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    findDuplicatesBruteForce(arr, size);
    return 0;
}