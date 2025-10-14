#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int min = 20, max = 230;
    int range = max - min + 1;
    
    int *count = (int*)calloc(range, sizeof(int));
    int *output = (int*)malloc(n * sizeof(int));
    
    // Conta a frequência de cada altura
    for(int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    
    // Calcula as posições cumulativas
    for(int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    // Constrói o array de saída
    for(int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    
    // Copia de volta para o array original
    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    free(count);
    free(output);
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
        
        countingSort(people, quant);
        
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

