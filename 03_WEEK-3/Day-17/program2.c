#include <stdio.h>
//program for union of arrays
void printUnion(int arr1[], int size1, int arr2[], int size2) {
    int unionArr[100];
    int unionSize = 0;

    for (int i = 0; i < size1; i++) {
        int exists = 0;
        for (int j = 0; j < unionSize; j++) {
            if (unionArr[j] == arr1[i]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            unionArr[unionSize] = arr1[i];
            unionSize++;
        }
    }

    for (int i = 0; i < size2; i++) {
        int exists = 0;
        for (int j = 0; j < unionSize; j++) {
            if (unionArr[j] == arr2[i]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            unionArr[unionSize] = arr2[i];
            unionSize++;
        }
    }

    for (int i = 0; i < unionSize; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 4, 5, 2, 6};
    int arr2[] = {2, 3, 5, 7};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printUnion(arr1, size1, arr2, size2);

    return 0;
}
