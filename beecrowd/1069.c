#include <stdio.h>
#include <stdlib.h>

int main() {
    char *expressao = NULL;
    size_t tamanho = 0;
    int n = 0;
    scanf("%d", &n);
    getchar();

    int i = 0;
    while (i < n) {
        int abre = 0;
        int fecha = 0;
        
        size_t bytes_lidos = getline(&expressao, &tamanho, stdin);
        if (bytes_lidos == -1) {
            break;
        }
        if (bytes_lidos > 0 && expressao[bytes_lidos - 1] == '\n') {
            expressao[bytes_lidos - 1] = '\0';
        }
        
        int j = 0;
        while(expressao[j] != '\0'){
            if(expressao[j] == '<') {
                abre += 1;
            }
            if(expressao[j] == '>' && abre > fecha) {
                fecha += 1;
            }
            j++;
        }
        printf("%d\n", fecha);
        
        i++;
    }
    
    free(expressao);
    return 0;
}
