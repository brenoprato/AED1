#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//node
typedef struct Node{
    char value;
    struct Node* next;
}Node;

//stack
typedef struct{
    Node* tail;
}Stack;

Stack* create_stack(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->tail = NULL;
    return s;
}

//push
void push_stack(Stack* s, char value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = s->tail;
    s->tail = newNode;
}

void pop_stack(Stack* s){
    if (s->tail == NULL) {return;}
    
    Node* tempNode = s->tail;
    s->tail = s->tail->next;
    free(tempNode);
}

int check_string(char* s) {
    Stack* stack = create_stack();
    int i = 0;
    
    while(s[i] != '\0') {
        if (s[i] == '(') {
            push_stack(stack, s[i]);
        }
        else if (s[i] == ')') {
            if (stack->tail == NULL) {
                free(stack);
                return 0;
            }
            else if (stack->tail->value == '(') {
                pop_stack(stack);
            }
        }
        i++;
    }
    
    int resultado = (stack->tail == NULL) ? 1 : 0;
    
    while(stack->tail != NULL) {
        pop_stack(stack);
    }
    free(stack);
    return resultado;
}

int main() {
    char *expressao = NULL;
    size_t size = 0;
    size_t read;
    
    while ((read = getline(&expressao, &size, stdin)) != -1) {
        if (read > 0 && expressao[read - 1] == '\n') {
            expressao[read - 1] = '\0';
        }
        
        if (check_string(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    free(expressao);
    return 0;
}
