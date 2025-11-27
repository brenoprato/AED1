#include <stdio.h>
#include <string.h>

#define INF 1000000000000LL
#define MAXC 10005
#define MAXV 50000

typedef struct { int to; long long cost; int next; } Edge;
Edge edges[4 * MAXV];
int head[2 * MAXC], ec;

long long distv[2 * MAXC];
int visited[2 * MAXC];

typedef struct { long long d; int u; } HeapItem;
HeapItem heap[200000];
int hs;

void heap_swap(int a, int b){
    HeapItem t = heap[a]; heap[a] = heap[b]; heap[b] = t;
}
void heap_push(int u, long long d){
    int i = hs++;
    heap[i].u = u; heap[i].d = d;
    while(i>0){
        int p = (i-1)/2;
        if(heap[p].d <= heap[i].d) break;
        heap_swap(p,i); i = p;
    }
}
HeapItem heap_pop(){
    HeapItem r = heap[0];
    heap[0] = heap[--hs];
    int i = 0;
    while(1){
        int l = 2*i+1, rgt = 2*i+2, s = i;
        if(l < hs && heap[l].d < heap[s].d) s = l;
        if(rgt< hs && heap[rgt].d < heap[s].d) s = rgt;
        if(s == i) break;
        heap_swap(i,s); i = s;
    }
    return r;
}

void add_edge(int u, int v, long long w){
    edges[ec].to=v; edges[ec].cost=w; edges[ec].next=head[u];
    head[u]=ec++;
}

int main(){
    int C, V;

    while( scanf("%d %d", &C, &V) == 2 ){
        int i;
        for(i=0;i<2*C;i++) head[i] = -1;
        ec = 0;

        for(i=0;i<V;i++){
            int a,b; long long g;
            scanf("%d %d %lld",&a,&b,&g);
            a--, b--; // cidades 0..C-1

            // alterna par/ímpar
            add_edge(2*a,   2*b+1, g);
            add_edge(2*a+1, 2*b,   g);
            add_edge(2*b,   2*a+1, g);
            add_edge(2*b+1, 2*a,   g);
        }

        for(i=0;i<2*C;i++) distv[i]=INF, visited[i]=0;

        hs = 0;
        distv[0] = 0;   // cidade 1 com par pedágios
        heap_push(0,0);

        while(hs){
            HeapItem h = heap_pop();
            int u = h.u;
            if(visited[u]) continue;
            visited[u]=1;

            for(i=head[u];i!=-1;i=edges[i].next){
                int v = edges[i].to;
                long long w = edges[i].cost;
                if(!visited[v] && distv[v] > distv[u] + w){
                    distv[v] = distv[u] + w;
                    heap_push(v, distv[v]);
                }
            }
        }

        long long ans = distv[2*(C-1)]; // cidade C com estado par
        if(ans >= INF) ans = -1;

        printf("%lld\n", ans);
    }

    return 0;
}
