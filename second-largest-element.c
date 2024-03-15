#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* Function to find and print the second largest element in an array */
void printSecondLargest(int *arr, int len)
{
    int i, largest, secondLargest;

    // Ensure the array has at least two elements
    if (len < 2) {
        printf("Array must have at least two elements.");
        return;
    }

    largest = secondLargest = INT_MIN;
    for (i = 0; i < len; i++) {
        // If current element is greater than the largest, update both largest and second largest
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        // If arr[i] is in between largest and second largest, update second largest
        else if (arr[i] > secondLargest && arr[i] != largest)
            secondLargest = arr[i];
    }
    
    // If secondLargest is still INT_MIN, no second largest element exists
    if (secondLargest == INT_MIN)
        printf("There is no second largest element.\n");
    else
        printf("The second largest element is %d.\n", secondLargest);
}

int main()
{
    int len;
    printf("Enter the length of the array: \n");
    scanf("%d", &len); 

    int *arr = (int *)malloc(len * sizeof(int));
    
    printf("Enter %d elements: \n", len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]); 
    }
    
    printSecondLargest(arr, len); 
    free(arr);
    
    return 0;
}
