#include <stdio.h>
#include <string.h>

#define MAXN 501
#define INF 1000000000

int N;
int adj_mat[MAXN][MAXN];
int adjT_mat[MAXN][MAXN];

void dfs1(int u, int visited[], int stack[], int *top) {
    visited[u] = 1;
    for (int v = 1; v <= N; v++) {
        if (adj_mat[u][v] && !visited[v]) {
            dfs1(v, visited, stack, top);
        }
    }
    stack[++(*top)] = u;
}

void dfs2(int u, int visited[], int comp[], int compId) {
    visited[u] = 1;
    comp[u] = compId;
    for (int v = 1; v <= N; v++) {
        if (adjT_mat[u][v] && !visited[v]) {
            dfs2(v, visited, comp, compId);
        }
    }
}

int main() {
    int E;
    while (1) {
        scanf("%d %d", &N, &E);
        if (N == 0 && E == 0) break;

        memset(adj_mat, 0, sizeof(adj_mat));
        memset(adjT_mat, 0, sizeof(adjT_mat));
        
        int weight[MAXN][MAXN];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                weight[i][j] = INF;
            }
        }

        for (int i = 0; i < E; i++) {
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H);
            adj_mat[X][Y] = 1;
            adjT_mat[Y][X] = 1;
            if (H < weight[X][Y]) {
                weight[X][Y] = H;
            }
        }

        int visited[MAXN] = {0};
        int stack[MAXN];
        int top = -1;

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs1(i, visited, stack, &top);
            }
        }

        int comp[MAXN];
        int compId = 0;
        memset(visited, 0, sizeof(visited));

        while (top >= 0) {
            int u = stack[top--];
            if (!visited[u]) {
                dfs2(u, visited, comp, compId);
                compId++;
            }
        }

        int dist_comp[MAXN][MAXN];
        for (int i = 0; i < compId; i++) {
            for (int j = 0; j < compId; j++) {
                dist_comp[i][j] = INF;
            }
            dist_comp[i][i] = 0;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (adj_mat[i][j] && comp[i] != comp[j]) {
                    int u_comp = comp[i];
                    int v_comp = comp[j];
                    if (weight[i][j] < dist_comp[u_comp][v_comp]) {
                        dist_comp[u_comp][v_comp] = weight[i][j];
                    }
                }
            }
        }

        for (int k = 0; k < compId; k++) {
            for (int i = 0; i < compId; i++) {
                if (dist_comp[i][k] == INF) continue;
                for (int j = 0; j < compId; j++) {
                    if (dist_comp[i][k] + dist_comp[k][j] < dist_comp[i][j]) {
                        dist_comp[i][j] = dist_comp[i][k] + dist_comp[k][j];
                    }
                }
            }
        }

        int K;
        scanf("%d", &K);
        for (int i = 0; i < K; i++) {
            int O, D;
            scanf("%d %d", &O, &D);
            if (comp[O] == comp[D]) {
                printf("0\n");
            } else if (dist_comp[comp[O]][comp[D]] == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", dist_comp[comp[O]][comp[D]]);
            }
        }
        printf("\n");
    }
    return 0;
}
