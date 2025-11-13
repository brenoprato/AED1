#include <stdio.h>
#include <stdlib.h>

#define MAX 10010

// Estruturas para lista encadeada
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

// Variáveis globais
List graph[MAX];
int visitado[MAX];
int N, M;
int temLoop;

// Adiciona aresta no grafo
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = graph[u].head;
    graph[u].head = newNode;
}

// Limpa o grafo para próximo caso de teste
void clearGraph() {
    for (int i = 1; i <= N; i++) {
        Node* current = graph[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        graph[i].head = NULL;
    }
}

// DFS para detectar ciclos
void busca(int u) {
    visitado[u] = 1; // Em visita
    
    Node* current = graph[u].head;
    while (current != NULL) {
        int v = current->vertex;
        
        if (visitado[v] == 0) {
            busca(v);
        } else if (visitado[v] == 1) {
            temLoop = 1; // Ciclo detectado
        }
        
        if (temLoop) return; // Para se já encontrou ciclo
        current = current->next;
    }
    
    visitado[u] = 2; // Visita completa
}

int main() {
    int T_casos;
    scanf("%d", &T_casos);

    while (T_casos--) {
        scanf("%d %d", &N, &M);
        
        // Inicialização
        clearGraph();
        for (int i = 1; i <= N; i++) {
            visitado[i] = 0;
        }
        
        // Construção do grafo
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            addEdge(A, B);
        }
        
        // Verificação de ciclos
        temLoop = 0;
        for (int i = 1; i <= N; i++) {
            if (visitado[i] == 0) {
                busca(i);
                if (temLoop) break;
            }
        }
        
        // Resultado
        printf(temLoop ? "SIM\n" : "NAO\n");
    }

    return 0;
}
