#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elementos maiores que key uma posição para frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int ncity;
    scanf("%d", &ncity);
    
    while(ncity--) {
        int quant;
        scanf("%d", &quant);
        int *people = (int*)malloc(quant * sizeof(int));
        
        for(int i = 0; i < quant; i++) {
            scanf("%d", &people[i]);
        }
        
        insertionSort(people, quant);
        
        for(int i = 0; i < quant; i++) {
            printf("%d", people[i]);
            if(i < quant - 1) {
                printf(" ");
            }
        }
        printf("\n");
        
        free(people);
    }
    return 0;
}
