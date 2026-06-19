#include <stdio.h>
//sort array in descending order
int main() {
    int arr[100];
    int size;
    int temp;

    printf("Enter size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0 || size > 100) {
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 1;
        }
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Array in descending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
