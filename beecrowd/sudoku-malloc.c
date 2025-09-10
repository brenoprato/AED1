#include <stdio.h>
#include <stdlib.h>

int main() {
    int *n;
    int *resultado;

    resultado = (int *)malloc(sizeof(int));
    *resultado = 1;

    n = (int *)malloc(sizeof(int));
    scanf("%d", n);

    for (int k = 0; k < *n; k++){
        int **matriz;
        matriz = (int **)malloc(9 * sizeof(int *));
        for (int i = 0; i < 9; i++) {
            matriz[i] = (int *)malloc(9 * sizeof(int));
        }
        
        int *linhas;
        linhas = (int *)malloc(9 * sizeof(int));
        
        int *colunas;
        colunas = (int *)malloc(9 * sizeof(int));

        int *square;
        square = (int *)malloc(9 * sizeof(int));

        // Lê a matriz
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        // Verifica linhas
        for (int i = 0; i < 9; i++){
            for (int m = 0; m < 9; m++) linhas[m] = 0;
            for (int j = 0; j < 9; j++){
                int num = matriz[i][j] - 1;
                if (linhas[num] == 1) {
                    *resultado = 0;
                }
                linhas[num] = 1;
            }
        }

        // Verifica colunas
        for (int j = 0; j < 9; j++){
            for (int m = 0; m < 9; m++) colunas[m] = 0;
            for (int i = 0; i < 9; i++){
                int num = matriz[i][j] - 1;
                if (colunas[num] == 1) {
                    *resultado = 0;
                }
                colunas[num] = 1;
            }
        }

        // Verifica quadrados 3x3
        for (int linha = 0; linha < 9; linha += 3){
            for (int coluna = 0; coluna < 9; coluna += 3){
                for (int m = 0; m < 9; m++) square[m] = 0;
                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 3; j++){
                        int num = matriz[linha + i][coluna + j] - 1;
                        if (square[num] == 1) {
                            *resultado = 0;
                        }
                        square[num] = 1;
                    }
                }
            }
        }

        if (*resultado == 1){
            printf("Instancia %d\nSIM\n\n", k + 1);
        } else {
            printf("Instancia %d\nNAO\n\n", k + 1);
        }

        free(linhas);
        free(colunas);
        free(square);
        
        for (int i = 0; i < 9; i++){
            free(matriz[i]);
        }
        free(matriz);
        
        *resultado = 1;
    }

    free(n);
    free(resultado);

    return 0;
}