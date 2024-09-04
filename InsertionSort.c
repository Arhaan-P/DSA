#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n, int ascending) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        if(ascending) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        else {
            while(j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* sales = (int*)malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }
    
    int* odd = (int*)malloc(n * sizeof(int));
    int* even = (int*)malloc(n * sizeof(int));
    int oddcount = 0, evencount = 0;
    
    for(int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even[evencount++] = sales[i];
        }
        else {
            odd[oddcount++] = sales[i];
        }
    }
    insertionSort(odd, oddcount, 1);
    insertionSort(even, evencount, 0);
    
    int oddidx = 0, evenidx = 0;
    
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            printf("%d ", even[evenidx++]);
        }
        else {
            printf("%d ", odd[oddidx++]);
        }
    }
}