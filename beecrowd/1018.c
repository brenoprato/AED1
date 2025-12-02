#include <stdio.h>

int main() {
    int valor;
    scanf("%d", &valor);
    
    printf("%d\n", valor);
    
    int notas[7] = {100, 50, 20, 10, 5, 2, 1};
    
    for (int i = 0; i < 7; i++) {
        int quantidade = valor / notas[i];
        printf("%d nota(s) de R$ %d,00\n", quantidade, notas[i]);
        valor %= notas[i];
    }
    return 0;
}
