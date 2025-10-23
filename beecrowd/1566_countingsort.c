#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int min = 20, max = 230;
    int range = max - min + 1;
    
    int *count = (int*)calloc(range, sizeof(int));

    for(int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    
    int index2 = 0;
    int index = 0;
    while(index2 < range){
        if(count[index2] > 0){
            arr[index] = index2 + min; 
            index++;  
            count[index2]--;
        }else{
            index2++;
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
