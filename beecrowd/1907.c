#include <stdio.h>
#include <stdlib.h>

#define MAX 1030

typedef struct {
    int x, y;
} Point;

char grid[MAX][MAX];
int visited[MAX][MAX];
int n, m;

//DFS iterativa
Point stack[MAX * MAX];
int top = -1;

void push(int x, int y) {
    top++;
    stack[top].x = x;
    stack[top].y = y;
}

Point pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void dfs(int startX, int startY) {
    push(startX, startY);
    visited[startX][startY] = 1;
    
    while (!isEmpty()) {
        Point current = pop();
        int x = current.x;
        int y = current.y;
        
        // Verificar vizinhos: cima, baixo, esquerda, direita
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                !visited[nx][ny] && grid[nx][ny] == '.') {
                visited[nx][ny] = 1;
                push(nx, ny);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }

    int clicks = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                clicks++;
            }
        }
    }

    printf("%d\n", clicks);
    return 0;
}
