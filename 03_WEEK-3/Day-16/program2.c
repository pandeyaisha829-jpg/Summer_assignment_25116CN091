#include <stdio.h>
#include <stdbool.h>
//to find maximum frequency element
int main() {
    int size;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];
    bool visited[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        visited[i] = false;
    }

    int maxElement = arr[0];
    int maxCount = 0;

    
    for (int i = 0; i < size; i++) {
        // Skip this element if it has already been counted
        if (visited[i]) {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = true;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxElement = arr[i];
        }
    }

    
    printf("\nElement with the maximum frequency: %d\n", maxElement);
    printf("It appears %d times.\n", maxCount);

    return 0;
}
