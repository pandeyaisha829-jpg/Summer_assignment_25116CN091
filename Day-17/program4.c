#include <stdio.h>
//program to find common elements
int main() {

    int array1[] = {4, 2, 9, 6, 2, 1, 8};
    int array2[] = {2, 5, 8, 2, 7, 4, 12};
    
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    
    int common[100];
    int k = 0; 

    for (int i = 0; i < size1; i++) {

        for (int j = 0; j < size2; j++) {
            if (array1[i] == array2[j]) {
            
                int isDuplicate = 0;
                for (int x = 0; x < k; x++) {
                    if (array1[i] == common[x]) {
                        isDuplicate = 1;
                        break;
                    }
                }
                
            
                if (!isDuplicate) {
                    common[k] = array1[i];
                    k++;
                }
                break; 
            }
        }
    }

    if (k > 0) {
        printf("Common elements are: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", common[i]);
        }
        printf("\n");
    } else {
        printf("No common elements found.\n");
    }

    return 0;
}
