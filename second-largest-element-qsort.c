#include <stdio.h>
#include <stdlib.h>
//Note: For second smallest element, sort in ascending order
//i.e change 'return (*(int*)b - *(int*)a)' to 'return (*(int*)a - *(int*)b)'



// Compare function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a); // Sort in descending order
}

void secondLargest(int *arr, int len) {
    // Sort the array in descending order
    qsort(arr, len, sizeof(int), compare);
    
    // Start from the second element as the first element is the largest
    for (int i = 1; i < len; i++) {
        // If the element is not equal to the largest element
        if (arr[i] != arr[0]) {
            printf("The second largest element is %d\n", arr[i]);
            return;
        }
    }
    // If all elements are equal
    printf("There is no second largest element\n");
}

int main() {
    int len;
    printf("Enter length of array: \n");
    scanf("%d", &len); 

    int *arr = (int *)malloc(len * sizeof(int));
    
    printf("Enter %d elements: \n", len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]); 
    }
    
    secondLargest(arr, len); 
    free(arr);
    
    return 0;
}
