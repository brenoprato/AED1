#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct{
    Node* head;
    Node* tail;
} Queue;

void push(Queue* q, int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = x;
    newNode->next = NULL;
    
    if(q->head == NULL){
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

void pop_x(Queue* q, int x){
    if(q->head == NULL) return;
    
    Node* temp = q->head;
    Node* prev = NULL;
    
    while(temp != NULL){
        if(temp->val == x){
            if(prev == NULL){
                q->head = temp->next;
                if(q->tail == temp) q->tail = NULL;
            } else {
                prev->next = temp->next;
                if(q->tail == temp) q->tail = prev;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void print_queue(Node* inicio){
    if(inicio == NULL) return;
    if(inicio->next != NULL){
        printf("%d ", inicio->val);
    }else{
        printf("%d\n", inicio->val);
    }
    print_queue(inicio->next);
}

void free_queue(Queue* q){
    Node* temp = q->head;
    while(temp != NULL){
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    q->head = NULL;
    q->tail = NULL;
}
 
int main() {
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    
    int n;
    scanf("%d", &n);
    while (n--){
        int x;
        scanf("%d", &x);
        push(&q, x);
    }
    
    scanf("%d", &n);
    while (n--){
        int x;
        scanf("%d", &x);
        pop_x(&q, x);
    }
    
    print_queue(q.head);
    free_queue(&q);
    
    return 0;
}
