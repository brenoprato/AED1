#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int k = 0; k < n; k++) {
        int matriz[9][9];
        int resultado = 1;

        // Lê a matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        // Verifica linhas
        for (int i = 0; i < 9 && resultado; i++) {
            int verificador[9] = {0};
            int *linha = matriz[i];
            
            for (int j = 0; j < 9; j++) {
                int num = linha[j] - 1;
                if (num < 0 || num >= 9 || verificador[num] == 1) {
                    resultado = 0;
                    break;
                }
                verificador[num] = 1;
            }
        }

        // Verifica colunas
        for (int j = 0; j < 9 && resultado; j++) {
            int verificador[9] = {0};
            
            for (int i = 0; i < 9; i++) {
                int num = matriz[i][j] - 1;
                if (num < 0 || num >= 9 || verificador[num] == 1) {
                    resultado = 0;
                    break;
                }
                verificador[num] = 1;
            }
        }

        // Verifica quadrados 3x3
        for (int bloco = 0; bloco < 9 && resultado; bloco++) {
            int verificador[9] = {0};
            int linha_inicio = (bloco / 3) * 3;
            int coluna_inicio = (bloco % 3) * 3;
            
            for (int i = linha_inicio; i < linha_inicio + 3; i++) {
                for (int j = coluna_inicio; j < coluna_inicio + 3; j++) {
                    int num = matriz[i][j] - 1;
                    if (num < 0 || num >= 9 || verificador[num] == 1) {
                        resultado = 0;
                        break;
                    }
                    verificador[num] = 1;
                }
                if (!resultado) break;
            }
        }

        printf("Instancia %d\n", k + 1);
        printf(resultado ? "SIM\n\n" : "NAO\n\n");
    }

    return 0;
}