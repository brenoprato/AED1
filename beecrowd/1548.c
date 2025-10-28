#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    while(n--) {
        int x;
        scanf("%d", &x);
        
        int* alunos_inicial = (int*)malloc(x * sizeof(int));
        int* alunos_final = (int*)malloc(x * sizeof(int));
        
        for (int i = 0; i < x; i++) {
            int temp;
            scanf("%d", &temp);
            alunos_inicial[i] = temp;
            alunos_final[i] = temp;
        }
        
        selectionSort(alunos_final, x);
        
        int resposta = 0;
        for (int i = 0; i < x; i++) {
            if (alunos_inicial[i] == alunos_final[i]) {
                resposta++;
            }
        }
        
        printf("%d\n", resposta);
        free(alunos_inicial);
        free(alunos_final);
    }
 
    return 0;
}
