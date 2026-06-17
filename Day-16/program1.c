#include <stdio.h>

// Function to find the missing number in array
int findMissingSum(int arr[], int size) {
    int n = size + 1; 
    

    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;


    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }


    return expectedSum - actualSum;
}

int main() {

    int arr[] = {1, 2, 6, 3, 5}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    int missingNum = findMissingSum(arr, size);
    
    printf("The missing number is: %d\n", missingNum);

    return 0;
}
