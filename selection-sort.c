//Find the smallest element and put it at the start of the array
//Find next smallest element and replace and keep doing
//For 'n' elements we need 'n-1' passes
//In each pass we find out the smallest element in the UNSORTED part
//After every pass, the UNSORTED array's length reduces by 1
#include<stdio.h>
#include<limits.h>
int main(){
    int arr[100], len;
    printf("Enter the length of the array: ");
    scanf("%d",&len);
    for(int i = 0; i < len; i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");

    //Sorting
    for(int i = 0; i < len - 1; i++){ //n-1 passes
        int min = INT_MAX;
        int min_index = -1;
        for(int j = i; j <= len - 1; j++){  // <= since entire array will be traversed
            if (min > arr[j]){
                min = arr[j];
                min_index = j;
            }
                                    
        }
        //Swap the min and first element of unsorted part (i loop)
        //Swap min_index and i
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
    printf("\n");

    for(int i = 0; i < len; i++){
        printf("%d ",arr[i]);
    }
}
