#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 105

int adj[MAX][MAX];
int adj_size[MAX]; 

int match[MAX];  
bool vis[MAX]; 
int A[MAX], B[MAX];

// Função DFS para encontrar caminho de aumento
bool dfs(int u) {
    // Percorre todos os vizinhos de u
    for (int i = 0; i < adj_size[u]; i++) {
        int v = adj[u][i]; // v é o índice do elemento em B
        
        if (vis[v]) continue;
        vis[v] = true;

        // Se v não tem par OU se o par atual de v pode encontrar outro caminho
        if (match[v] < 0 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

void solve(int t) {
    int n, m;

    //A
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    //B
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }

    memset(adj_size, 0, sizeof(adj_size));

    // Construção do Grafo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Regra: B[j] é múltiplo de A[i]
            if (A[i] == 0) {
                if (B[j] == 0) {
                    adj[i][adj_size[i]] = j; // Adiciona aresta
                    adj_size[i]++;
                }
            } else {
                if (B[j] % A[i] == 0) {
                    adj[i][adj_size[i]] = j; // Adiciona aresta
                    adj_size[i]++;
                }
            }
        }
    }

    int result = 0;
    // Inicializa o array de matches com -1
    memset(match, -1, sizeof(match));

    for (int i = 0; i < n; i++) {
        // Reseta o vetor de visitados para cada tentativa de emparelhamento
        memset(vis, 0, sizeof(vis));
        
        if (dfs(i)) {
            result++;
        }
    }

    printf("Case %d: %d\n", t, result);
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    
    return 0;
}
