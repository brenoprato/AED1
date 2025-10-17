#include <stdio.h>

void merge(int arr[], int l, int mid, int r){
    int lSize = mid - l + 1;
    int rSize = r - mid;
    
    //aloca e cria um vetor metade esquerda e direita
    int *vl = malloc(lSize * sizeof(int));
    int *vr = malloc(rSize * sizeof(int));
    
    for (int i = 0; i < lSize; i++){
        vl[i] = arr[l+i];
    }
    for (int i = 0; i < rSize; i++){
        vr[i] = arr[mid+i+1];
    }
    
    //comparar os vetores e mescla
    int i = 0, j = 0, k = l;
    
    while(i < lSize && j < rSize){
        if(vl[i] <= vr[j]){
            arr[k] = vl[i];
            i++;
        }else{
            arr[k] = vr[j];
            j++;
        }
        k++;
    }
        while (i < lSize) {
        arr[k] = vl[i];
        i++;
        k++;
    }
    // Se sobrou cartas só na pilha R, coloco todas  
    while (j < rSize) {
        arr[k] = vr[j];
        j++;
        k++;
    }
    free(vl);
    free(vr);
}

void mergedSort(int arr[], int l, int r){
    if (l<r){
        int mid = l + (r - l) / 2;
        
        mergedSort(arr, l, mid);
        
        mergedSort(arr, mid + 1, r);
        
        merge(arr, l, mid, r);
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
        
        mergedSort(people, 0, quant - 1);
        
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
