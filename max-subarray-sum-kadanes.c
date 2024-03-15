#include <stdio.h>
#include <stdlib.h>

// Function to calculate the maximum subarray sum
int maxSubarraySum(int *arr, int size);

int main() {
    int len;

    printf("Enter the length of the array: ");
    scanf("%d", &len);
    
    int *arr = (int *)malloc(len * sizeof(int));

    printf("Enter the elements of the array:\n");
    for(int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Function call
    maxSubarraySum(arr, len);
    
    return 0;
}

// Function to find the maximum subarray sum
int maxSubarraySum(int *arr, int size) {
    int maxSum = arr[0], curSum = 0;

    // Iterating 
    for(int i = 0; i < size; i++) {
        curSum += arr[i];
        
        // If the current sum becomes less than the current element,
        // start a new subarray from the current element
        // Don't unnecessarily collect negative values, it will make the sum smaller
        if(curSum < arr[i]) {
            curSum = arr[i];
        }
        
        // Update maximum sum if current sum is greater
        if(curSum > maxSum) {
            maxSum = curSum;
        }
    }
    printf("Maximum subarray sum: %d\n", maxSum);
}