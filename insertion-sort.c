#include <stdio.h>

int main() {
    int arr[100], len; 

    printf("Enter the length of the array: ");
    scanf("%d", &len); 

    printf("Enter %d elements:\n", len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]); 
    }

    printf("\n");

    for (int i = 1; i < len; i++) { // Iterate over the array starting from the second element
        int j = i;
        // Insertion sort: Swap adjacent elements until the current element is in its sorted position
        while (j > 0 && arr[j] < arr[j - 1]) {  
            int temp = arr[j]; // Temporary variable to store the current element
            arr[j] = arr[j - 1]; // Move the larger element one position ahead
            arr[j - 1] = temp; // Place the smaller element in the correct position
            j--; // Move to the previous position
        }
        // If arr[j] >= arr[j-1], the while loop ends
    }

    printf("\nSorted array:\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]); 
    }

    return 0;
}
