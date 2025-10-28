#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* create_node(int x, Node* prox) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = x;
    newNode->next = prox;
    return newNode;
}

void pop(Stack* curr) {
    if (curr->top == NULL) return;
    Node* trash = curr->top;
    curr->top = curr->top->next;
    free(trash);
}

void push(Stack* curr, int val) {
    Node* newNode = create_node(val, curr->top);
    curr->top = newNode;
}

int top(Stack* curr) {
    if (curr->top == NULL) return 0;
    return curr->top->val;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int first;
        int* target = (int*)malloc(n * sizeof(int));
        while (scanf("%d", &first) == 1 && first != 0) {
            target[0] = first;
            for (int i = 1; i < n; i++) {
                scanf("%d", &target[i]);
            }
            
            Stack wagons = {NULL};
            int ptr = 0;
            for (int i = 1; i <= n; i++) {
                push(&wagons, i);
                while (ptr < n && top(&wagons) == target[ptr]) {
                    pop(&wagons);
                    ptr++;
                }
            }
            
            printf(top(&wagons) == 0 ? "Yes\n" : "No\n");
        }
        printf("\n");
        free(target);
    }
    return 0;
}
