#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 50000
#define MAX_VERTICES 40000

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];
int rank[MAX_VERTICES];

// Função Find com compressão de caminho
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Função Union com união por rank
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Comparador para ordenar arestas por peso
int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

int main() {
    int M, N;
    while (1) {
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0) break;

        // Inicializa estruturas Union-Find
        for (int i = 0; i < M; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        // Lê todas as arestas
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        }

        // Ordena arestas por peso (crescente)
        qsort(edges, N, sizeof(Edge), compareEdges);

        // Algoritmo de Kruskal
        int mstWeight = 0;
        for (int i = 0; i < N; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            // Se estão em componentes diferentes, adiciona à MST
            if (find(u) != find(v)) {
                unionSets(u, v);
                mstWeight += edges[i].weight;
            }
        }

        printf("%d\n", mstWeight);
    }
    return 0;
}
