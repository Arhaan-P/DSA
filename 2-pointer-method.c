#include<stdio.h>
#include<stdlib.h>

void findPair(int *arr, int len, int target);

int main(){
    int array[100], length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    
    int *arr = (int *)malloc(length * sizeof(int));
    
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < length; i++){
        scanf("%d", &arr[i]);
    }
    
    int target;
    printf("\nEnter the target sum: ");
    scanf("%d", &target);
    
    findPair(arr, length, target);
    free(arr);
    return 0;
}

void findPair(int *arr, int len, int target){
    int i = 0;       // Initialise a left pointer to start of array
    int j = len - 1; // Initialise a right pointer to end of array
    int flag = 0;
    
    while(i < j){
        int currentSum = arr[i] + arr[j];
        if(currentSum == target){
            printf("Pair found: %d + %d = %d\n", arr[i], arr[j], target);
            i++;
            j--;
            flag = 1;
        }
        else if(currentSum < target){
            i++; // Move to the right to increase the sum since the array is sorted
        }
        else{
            j--; // Move to the left to decrease the sum since the array is sorted
        }
    }
    if(!flag){
        printf("\nNo pair found\n");
    }
}
