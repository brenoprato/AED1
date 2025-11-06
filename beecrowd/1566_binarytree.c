#include <stdio.h>
#include <stdlib.h>

// Nó da árvore binária
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Inserir um valor na árvore (com criação direta do nó)
Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Percorre e imprime em ordem
void inOrderPrint(Node* root, int* isFirst) {
    if (root != NULL) {
        inOrderPrint(root->left, isFirst);
        
        if (!(*isFirst)) {
            printf(" ");
        } else {
            *isFirst = 0;
        }
        
        printf("%d", root->value);
        inOrderPrint(root->right, isFirst);
    }
}

// Liberar memória da árvore
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int ncity;
    scanf("%d", &ncity);
    
    while(ncity--) {
        int quant;
        scanf("%d", &quant);
        Node* root = NULL;
        int age;
        
        // Lê e insere os valores na árvore
        for(int i = 0; i < quant; i++) {
            scanf("%d", &age);
            root = insert(root, age);
        }
        
        // Imprime os valores ordenados
        int isFirst = 1;
        inOrderPrint(root, &isFirst);
        printf("\n");
        
        // Libera a memória
        freeTree(root);
    }
    return 0;
}
