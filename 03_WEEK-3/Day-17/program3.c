#include <stdio.h>
#include <stdbool.h>
//program for intersection of arrays
int find_intersection(int* arrays[], int sizes[], int num_arrays, int* result) {
    if (num_arrays == 0) {
        return 0;
    }

    int res_count = 0;

    for (int i = 0; i < sizes[0]; i++) {
        int current_element = arrays[0][i];
        
        bool already_added = false;
        for (int j = 0; j < res_count; j++) {
            if (result[j] == current_element) {
                already_added = true;
                break;
            }
        }
        if (already_added) {
            continue;
        }

        bool present_in_all = true;
        for (int j = 1; j < num_arrays; j++) {
            bool found_in_current = false;
            for (int k = 0; k < sizes[j]; k++) {
                if (arrays[j][k] == current_element) {
                    found_in_current = true;
                    break;
                }
            }
            if (!found_in_current) {
                present_in_all = false;
                break;
            }
        }

        if (present_in_all) {
            result[res_count] = current_element;
            res_count++;
        }
    }

    return res_count;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 2};
    int arr2[] = {2, 4, 6, 8, 2};
    int arr3[] = {1, 2, 4, 7, 2};

    int* arrays[] = {arr1, arr2, arr3};
    int sizes[] = {6, 5, 5};
    int num_arrays = 3;

    int result[6]; 
    int intersection_size = find_intersection(arrays, sizes, num_arrays, result);

    printf("Intersection: ");
    for (int i = 0; i < intersection_size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
