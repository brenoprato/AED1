#include <stdio.h>
#include <stdbool.h>

int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int start;
        scanf("%d", &start);
        int V, A;
        scanf("%d %d", &V, &A);
        bool edges[50][50] = {false};
        int count = 0;
        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            
            //grafo ñ direcionado, troca valores de arestas iguais.
            
            if (u > v) {
                int temp = u;
                u = v;
                v = temp;
            }
            
            //Marcando aresta u~v
            
            if (!edges[u][v]) {
                edges[u][v] = true;
                count++;
            }
        }
        printf("%d\n", 2 * count); //vai e volta
    }
    return 0;
}
