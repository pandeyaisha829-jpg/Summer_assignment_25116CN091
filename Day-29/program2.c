#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int arr[], int size, int element, int position) {
    if (size >= MAX) {
        printf("Array overflow. Cannot insert.\n");
        return size;
    }
    if (position < 1 || position > size + 1) {
        printf("Invalid position.\n");
        return size;
    }
    for (int i = size; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    printf("Element inserted successfully.\n");
    return size + 1;
}

int deleteElement(int arr[], int size, int position) {
    if (size == 0) {
        printf("Array underflow. Cannot delete.\n");
        return size;
    }
    if (position < 1 || position > size) {
        printf("Invalid position.\n");
        return size;
    }
    printf("Deleted element: %d\n", arr[position - 1]);
    for (int i = position - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

void search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element found at position %d.\n", i + 1);
            return;
        }
    }
    printf("Element not found in the array.\n");
}

int main() {
    int arr[MAX];
    int size = 0;
    int choice, element, position;

    while (1) {
        printf("\n--- ARRAY OPERATIONS MENU ---\n");
        printf("1. Create/Initialize Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &size);
                if (size < 0 || size > MAX) {
                    printf("Invalid size. Resetting to 0.\n");
                    size = 0;
                    break;
                }
                printf("Enter %d elements:\n", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                display(arr, size);
                break;

            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (1 to %d): ", size + 1);
                scanf("%d", &position);
                size = insert(arr, size, element, position);
                break;

            case 4:
                printf("Enter position to delete (1 to %d): ", size);
                scanf("%d", &position);
                size = deleteElement(arr, size, position);
                break;

            case 5:
                printf("Enter element to search: ");
                scanf("%d", &element);
                search(arr, size, element);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
