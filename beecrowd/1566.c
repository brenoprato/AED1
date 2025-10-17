#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int min = 20, max = 230;
    int range = max - min + 1;
    
    int *count = (int*)calloc(range, sizeof(int));
    
    // Conta a frequência de cada altura
    for(int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    
    // Vetor recebe alturas
    int index = 0;
    for (int i = 0; i < range; i++){
        while(count[i] > 0){
            arr[index] = i+min; 
            index++;
            count[i]--;
        }
    }
    
    free(count);
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
