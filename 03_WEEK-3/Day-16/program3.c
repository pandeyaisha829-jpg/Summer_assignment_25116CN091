#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//find pair with given sum
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
bool findPairTwoPointer(int arr[], int size, int target) {

    qsort(arr, size, sizeof(int), compare);

    int left = 0;
    int right = size - 1;

    while (left < right) {
        int current_sum = arr[left] + arr[right];

        if (current_sum == target) {
            printf("Pair found (Two-Pointer): %d + %d = %d\n", arr[left], arr[right], target);
            return true;
        }
        else if (current_sum < target) {
            left++; 
        } 
        else {
            right--; 
        }
    }
    return false;
}


bool findPairBruteForce(int arr[], int size, int target) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Pair found (Brute-Force): %d + %d = %d\n", arr[i], arr[j], target);
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {8, 7, 2, 5, 3, 1};
    int target = 10;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Target Sum: %d\n\n", target);


    if (!findPairBruteForce(arr, size, target)) {
        printf("No pair found using Brute-Force.\n");
    }

    
    if (!findPairTwoPointer(arr, size, target)) {
        printf("No pair found using Two-Pointer.\n");
    }

    return 0;
}
