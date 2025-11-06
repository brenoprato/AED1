#include <stdio.h>
#include <stdlib.h>

//nó da árvore
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

//criar um novo nó
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//inserir na árvore
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

//percursos com controle de impressão (sem espaço no final)
void preOrder(Node* root, int* first) {
    if (root != NULL) {
        if (*first) {
            printf("%d", root->value);
            *first = 0;
        } else {
            printf(" %d", root->value);
        }
        preOrder(root->left, first);
        preOrder(root->right, first);
    }
}

void inOrder(Node* root, int* first) {
    if (root != NULL) {
        inOrder(root->left, first);
        if (*first) {
            printf("%d", root->value);
            *first = 0;
        } else {
            printf(" %d", root->value);
        }
        inOrder(root->right, first);
    }
}

void postOrder(Node* root, int* first) {
    if (root != NULL) {
        postOrder(root->left, first);
        postOrder(root->right, first);
        if (*first) {
            printf("%d", root->value);
            *first = 0;
        } else {
            printf(" %d", root->value);
        }
    }
}

//liberar a memória da árvore
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int C; //casos
    scanf("%d", &C);
    
    for (int case_num = 1; case_num <= C; case_num++) {
        int N;
        scanf("%d", &N);
        
        Node* root = NULL;
        
        // Ler e inserir os números na árvore
        for (int i = 0; i < N; i++) {
            int num;
            scanf("%d", &num);
            root = insert(root, num);
        }
        
        // Imprimir o caso
        printf("Case %d:\n", case_num);
        
        // Pré-ordem
        int first = 1;
        printf("Pre.: ");
        preOrder(root, &first);
        printf("\n");
        
        // Em-ordem
        first = 1;
        printf("In..: ");
        inOrder(root, &first);
        printf("\n");
        
        // Pós-ordem
        first = 1;
        printf("Post: ");
        postOrder(root, &first);
        printf("\n");
        
        // Linha em branco após cada caso
        printf("\n");
        
        // Liberar memória
        freeTree(root);
    }
    
    return 0;
}
