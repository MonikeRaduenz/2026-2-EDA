#include <stdio.h>
#include <stdlib.h>

// Implementação com ponteiros e alocação dinâmica de memória
typedef struct {
    struct No *anterior; // ponteiro para o nó anterior
    int v;               // valor do nó
} No;
typedef struct {
    No *topo; // ponteiro para o topo da pilha
} Pilha;

// Criar uma nova pilha
Pilha *cria() {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL; // inicializa o topo da pilha com nulo
    return p;
}

// Inserir um novo elemento na pilha
void push(Pilha *p, int v) {
    No *no = malloc(sizeof(No));
    no->v = v;
    no->anterior = p->topo;
    p->topo = no;
}

// Verificar se a pilha está vazia
int vazia(Pilha *p) {
    return p->topo == NULL;
}

// Remover elemento do topo na pilha
int pop(Pilha *p) {
    int v;

    if (vazia(p)) {
        printf("Pilha vazia");
        exit(-1);
    }
    else {
        No *no = p->topo;
        v = no->v; // recupera valor do topo
        p->topo = no->anterior;
        free(no);
    }
    return v;
}

// Libera memória da pilha
void limpa(Pilha *p) {
    while (p->topo != NULL) {
        No *no = p->topo;
        p->topo = no->anterior;
        free(no);
    }
    free(p);
}

// Visitar todos os elementos da pilha
void percorre(Pilha *p) {
    while (vazia(p)) {
        int v = pop(p);

        printf("%d", v);
    }
}
