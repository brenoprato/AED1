#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    scanf("%d", &N);

    int *x = (int *)malloc(N * sizeof(int));
    int *menor = (int *)malloc(sizeof(int));
    int *pos = (int *)malloc(sizeof(int));
    
    for (int i = 0; i < N; i++){
        scanf("%d", &x[i]);
    }

    *menor = x[0];
    *pos = 0;

    for (int i = 1; i < N; i++){
        if (*menor > x[i]){
            *menor = x[i];
            *pos = i;
        }
    }

    printf("Menor valor: %d\n", *menor);
    printf("Posicao: %d\n", *pos);

    free(x);
    free(menor);
    free(pos);
    return 0;
}