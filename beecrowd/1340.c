#include <stdio.h>
#include <stdlib.h>

//NÓ
typedef struct No {
    int valor;
    struct No* proximo;
} No;

//ESTRUTURAS
typedef struct {
    No* topo;
} Pilha;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

typedef struct {
    No* inicio;
} FilaPrioridade;

//CRIAÇÃO
Pilha* criar_pilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

Fila* criar_fila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

FilaPrioridade* criar_prioridade() {
    FilaPrioridade* fp = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    fp->inicio = NULL;
    return fp;
}

//INSERÇÃO
void pilha_inserir(Pilha* p, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}

void fila_inserir(Fila* f, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (f->fim == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }
}

void prioridade_inserir(FilaPrioridade* fp, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    
    // Inserir ordenado (maior → menor)
    if (fp->inicio == NULL || valor > fp->inicio->valor) {
        novo->proximo = fp->inicio;
        fp->inicio = novo;
    } else {
        No* atual = fp->inicio;
        while (atual->proximo != NULL && atual->proximo->valor >= valor) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
}

//REMOÇÃO
int pilha_remover(Pilha* p) {
    if (p->topo == NULL) return -1; // Indicador de erro
    
    No* temp = p->topo;
    int valor_removido = temp->valor;
    p->topo = p->topo->proximo;
    free(temp);
    
    return valor_removido;
}

int fila_remover(Fila* f) {
    if (f->inicio == NULL) return -1; // Indicador de erro
    
    No* temp = f->inicio;
    int valor_removido = temp->valor;
    f->inicio = f->inicio->proximo;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(temp);
    return valor_removido;
}

int prioridade_remover(FilaPrioridade* fp) {
    if (fp->inicio == NULL) return -1; // Indicador de erro
    
    No* temp = fp->inicio;
    int valor_removido = temp->valor;
    fp->inicio = fp->inicio->proximo;
    free(temp);
    
    return valor_removido;
}

//LIBERAR MEMÓRIA
void liberar_lista(No* inicio) {
    while (inicio != NULL) {
        No* temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }
}

void destruir_pilha(Pilha* p) {
    liberar_lista(p->topo);
    free(p);
}

void destruir_fila(Fila* f) {
    liberar_lista(f->inicio);
    free(f);
}

void destruir_prioridade(FilaPrioridade* fp) {
    liberar_lista(fp->inicio);
    free(fp);
}

//MAIN
int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        Pilha* pilha = criar_pilha();
        Fila* fila = criar_fila();
        FilaPrioridade* prioridade = criar_prioridade();
        
        int pode_pilha = 1, pode_fila = 1, pode_prioridade = 1;
        
        for (int i = 0; i < n; i++) {
            int op, valor;
            scanf("%d", &op);
            
            if (op == 1) {
                //INSERIR
                scanf("%d", &valor);
                
                if (pode_pilha) pilha_inserir(pilha, valor);
                if (pode_fila) fila_inserir(fila, valor);
                if (pode_prioridade) prioridade_inserir(prioridade, valor);
                
            } else {
                //REMOVER
                scanf("%d", &valor);
                
                if (pode_pilha) {
                    int removido = pilha_remover(pilha);
                    if (removido == -1 || removido != valor) {
                        pode_pilha = 0;
                    }
                }
                
                if (pode_fila) {
                    int removido = fila_remover(fila);
                    if (removido == -1 || removido != valor) {
                        pode_fila = 0;
                    }
                }
                
                if (pode_prioridade) {
                    int removido = prioridade_remover(prioridade);
                    if (removido == -1 || removido != valor) {
                        pode_prioridade = 0;
                    }
                }
            }
        }
        
        int total = pode_pilha + pode_fila + pode_prioridade;
        
        if (total == 0) {
            printf("impossible\n");
        } else if (total == 1) {
            if (pode_pilha) printf("stack\n");
            else if (pode_fila) printf("queue\n");
            else printf("priority queue\n");
        } else {
            printf("not sure\n");
        }

        destruir_pilha(pilha);
        destruir_fila(fila);
        destruir_prioridade(prioridade);
    }
    
    return 0;
}
