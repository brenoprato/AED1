#include <stdio.h>

#define INF 1000000000
#define MAXN 260
#define MAXM 62500

typedef struct { int to, cost, next; } Edge;
Edge edges[MAXM * 2];
int head[MAXN], edge_count;

typedef struct { int node, dist; } HeapItem;
HeapItem heap[MAXN * 20];
int heap_size;

int distv[MAXN], visited[MAXN];

// min-heap para Dijkstra
void heap_swap(int a, int b) {
    HeapItem t = heap[a]; heap[a] = heap[b]; heap[b] = t;
}
void heap_push(int node, int dist) {
    int i = heap_size++;
    heap[i].node = node; heap[i].dist = dist;
    while (i > 0) { // sobe enquanto menor que o pai
        int p = (i - 1) / 2;
        if (heap[p].dist <= heap[i].dist) break;
        heap_swap(p, i);
        i = p;
    }
}
HeapItem heap_pop() {
    HeapItem r = heap[0];
    heap[0] = heap[--heap_size];
    int i = 0;
    while (1) { // desce enquanto tiver filho menor
        int l = 2*i + 1, rgt = 2*i + 2, s = i;
        if (l < heap_size && heap[l].dist < heap[s].dist) s = l;
        if (rgt < heap_size && heap[rgt].dist < heap[s].dist) s = rgt;
        if (s == i) break;
        heap_swap(i, s);
        i = s;
    }
    return r;
}

void add_edge(int u, int v, int cost) {
    edges[edge_count].to = v;
    edges[edge_count].cost = cost;
    edges[edge_count].next = head[u];
    head[u] = edge_count++;
}

void dijkstra(int start, int N) {
    int i;
    for (i = 0; i < N; i++) distv[i] = INF, visited[i] = 0;
    heap_size = 0;
    distv[start] = 0;
    heap_push(start, 0);

    while (heap_size > 0) {
        HeapItem h = heap_pop();
        int u = h.node;
        if (visited[u]) continue;
        visited[u] = 1;

        for (i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to, w = edges[i].cost;
            if (!visited[v] && distv[v] > distv[u] + w) {
                distv[v] = distv[u] + w;
                heap_push(v, distv[v]);
            }
        }
    }
}

int main() {
    int N, M, C, K;

    while (1) {
        if (scanf("%d %d %d %d", &N, &M, &C, &K) != 4) return 0;
        if (!N && !M && !C && !K) break;

        int i;
        for (i = 0; i < N; i++) head[i] = -1;
        edge_count = 0;

        static int U[MAXM], V[MAXM], P[MAXM];
        for (i = 0; i < M; i++) scanf("%d %d %d", &U[i], &V[i], &P[i]);

        for (i = 0; i < M; i++) {
            int u = U[i], v = V[i], p = P[i];
            int ur = (u < C), vr = (v < C);

            // regra da rota: cidades < C só podem avançar i -> i+1
            if (ur && vr) {
                if (v == u + 1) add_edge(u, v, p);
                if (u == v + 1) add_edge(v, u, p);
            }
            else if (!ur && !vr) {
                add_edge(u, v, p);
                add_edge(v, u, p);
            }
            else {
                // entrada na rota só pode ir para a cidade da rota
                if (ur) add_edge(v, u, p);
                else   add_edge(u, v, p);
            }
        }

        dijkstra(K, N);
        printf("%d\n", distv[C - 1]);
    }

    return 0;
}
