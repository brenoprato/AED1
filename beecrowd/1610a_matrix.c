#include <stdio.h>
#include <stdlib.h>

#define MAX 10010

int visitado[MAX];
int lista_vizinhos[MAX][MAX]; 
int total_vizinhos[MAX];      
int N, M;
int temLoop;                  

void busca(int u) {
    visitado[u] = 1; 

    for (int i = 0; i < total_vizinhos[u]; i++) {
        int v = lista_vizinhos[u][i];

        if (visitado[v] == 0) { 
            busca(v);
        } else if (visitado[v] == 1) { 
            temLoop = 1;
            return;
        }
    }

    visitado[u] = 2; 
}

int main() {
    int T_casos;
    scanf("%d", &T_casos);

    while (T_casos--) {
        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++) {
            total_vizinhos[i] = 0;
            visitado[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            lista_vizinhos[A][total_vizinhos[A]++] = B;
        }

        temLoop = 0; 

        for (int i = 1; i <= N; i++) {
            if (visitado[i] == 0) {
                busca(i);
                if (temLoop) break; 
            }
        }

        if (temLoop)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
