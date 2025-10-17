#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        // Encontra o menor elemento no restante do array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Troca o menor elemento com a posição atual
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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
        
        selectionSort(people, quant);
        
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
