#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int k = 1; k <= n; k++) {
        int matriz[9][9];
        char resultado[4] = "SIM";
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        for (int i = 0; i < 9; i++) {
            int soma = 0;
            int contador[10] = {0};
            for (int j = 0; j < 9; j++) {
                soma += matriz[i][j];
                contador[matriz[i][j]]++;
            }
            if (soma != 45) strcpy(resultado, "NAO");
            for (int x = 1; x <= 9; x++) {
                if (contador[x] != 1) strcpy(resultado, "NAO");
            }
        }

        for (int j = 0; j < 9; j++) {
            int soma = 0;
            int contador[10] = {0};
            for (int i = 0; i < 9; i++) {
                soma += matriz[i][j];
                contador[matriz[i][j]]++;
            }
            if (soma != 45) strcpy(resultado, "NAO");
            for (int x = 1; x <= 9; x++) {
                if (contador[x] != 1) strcpy(resultado, "NAO");
            }
        }

        for (int linha = 0; linha < 9; linha += 3) {
            for (int coluna = 0; coluna < 9; coluna += 3) {
                int soma = 0;
                int contador[10] = {0};
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int num = matriz[linha + i][coluna + j];
                        soma += num;
                        contador[num]++;
                    }
                }
                if (soma != 45) strcpy(resultado, "NAO");
                for (int x = 1; x <= 9; x++) {
                    if (contador[x] != 1) strcpy(resultado, "NAO");
                }
            }
        }

        printf("Instancia %d\n%s\n\n", k, resultado);
    }

    return 0;
}
