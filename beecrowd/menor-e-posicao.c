#include <stdio.h>
 
int main() {
 
    int N, menor, pos = 0;
    scanf("%d", &N);
    
    int X[N];
    
    scanf("%d", &X[0]);
    menor = X[0];
    
    for (int i = 1; i < N; i++) {
        scanf("%d", &X[i]);
        if (menor > X[i]) {
            menor = X[i];
            pos = i;
        }
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);
 
    return 0;
}


