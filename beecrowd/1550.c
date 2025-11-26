#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20000

int reverse(int x) {
    int rev = 0;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev;
}

int bfs(int start, int target) {
    if (start == target) return 0;
    
    int dist[MAX + 1];
    memset(dist, -1, sizeof(dist));
    
    int queue[MAX];
    int front = 0, rear = 0;
    
    dist[start] = 0;
    queue[rear++] = start;
    
    while (front < rear) {
        int current = queue[front++];
        
        // Operação 1: Somar 1
        int next1 = current + 1;
        if (next1 <= MAX && dist[next1] == -1) {
            dist[next1] = dist[current] + 1;
            if (next1 == target) return dist[next1];
            queue[rear++] = next1;
        }
        
        // Operação 2: Inverter dígitos
        int next2 = reverse(current);
        if (next2 <= MAX && dist[next2] == -1) {
            dist[next2] = dist[current] + 1;
            if (next2 == target) return dist[next2];
            queue[rear++] = next2;
        }
    }
    
    return -1; // Não deve acontecer dado o enunciado
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }
    
    return 0;
}
