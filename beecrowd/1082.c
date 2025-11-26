#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 26

typedef struct {
    int vertices;
    int arestas;
    int matriz_adj[MAX_VERTICES][MAX_VERTICES];
} Grafo;

void inicializarGrafo(Grafo *g, int v, int e) {
    g->vertices = v;
    g->arestas = e;
    memset(g->matriz_adj, 0, sizeof(g->matriz_adj));
}

void adicionarAresta(Grafo *g, char u, char v) {
    int idx_u = u - 'a';
    int idx_v = v - 'a';
    g->matriz_adj[idx_u][idx_v] = 1;
    g->matriz_adj[idx_v][idx_u] = 1;
}

// Função DFS para percorrer o componente conexo
void DFS(Grafo *g, int vertice, int visitado[], char componente[], int *tam_componente) {
    visitado[vertice] = 1;
    componente[(*tam_componente)++] = 'a' + vertice;
    
    for (int i = 0; i < g->vertices; i++) {
        if (g->matriz_adj[vertice][i] && !visitado[i]) {
            DFS(g, i, visitado, componente, tam_componente);
        }
    }
}

// Função para comparar caracteres (usada no qsort)
int compararChars(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

int main() {
    int testes, caso = 1;
    scanf("%d", &testes);
    
    while(testes--){
        int v, e;
        scanf("%d %d", &v, &e);
        
        Grafo g;
        inicializarGrafo(&g, v, e);
        
        // Ler as arestas
        for(int i = 0; i < e; i++) {
            char u, v;
            scanf(" %c %c", &u, &v);
            adicionarAresta(&g, u, v);
        }
        
        int visitado[MAX_VERTICES] = {0};
        int num_componentes = 0;
        
        printf("Case #%d:\n", caso++);
        
        // Encontrar componentes conexos
        for(int i = 0; i < v; i++) {
            if(!visitado[i]) {
                char componente[MAX_VERTICES];
                int tam_componente = 0;
                
                DFS(&g, i, visitado, componente, &tam_componente);
                
                // Ordenar o componente em ordem alfabética
                qsort(componente, tam_componente, sizeof(char), compararChars);
                
                // Imprimir o componente
                for(int j = 0; j < tam_componente; j++) {
                    printf("%c,", componente[j]);
                }
                printf("\n");
                
                num_componentes++;
            }
        }
        
        printf("%d connected components\n\n", num_componentes);
    }
    
    return 0;
}
