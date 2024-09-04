#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort (char names[][100], int n) {
    int idx = -1;
    char temp[100];
    
    printf("Initial order: ");
    for (int i = 0; i < n; i++) {
        printf("%s ", names[i]);
    }
    printf("\n");
    
    for (int i = 0; i < n - 1; i++) {
        idx = i;
        
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[j], names[idx]) < 0) {
                idx = j;
            }
        }
        
        if (idx != i) {
            strcpy(temp, names[i]);
            strcpy(names[i], names[idx]);
            strcpy(names[idx], temp);
        }
        
        printf("After Iteration %d: ", i + 1);
        
        for(int j = 0; j < n; j++) {
            printf("%s ", names[j]);
        }
        printf("\n");
    }
    
    printf("Sorted order: ");
    for (int i = 0; i < n; i++) {
        printf("%s ", names[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char names[n][100];
    
    for(int i = 0; i < n; i++) {
        scanf("%s ", &names[i]);
    }
    
    selectionSort(names, n);
}