#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* anterior;
}No;

typedef struct {
    No* topo;
}Pilha;

Pilha* criar(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
} 

int vazia(Pilha* pilha){
    return pilha->topo == NULL;
}

void push(Pilha* pilha, int valor){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->anterior = pilha->topo;

    pilha->topo = no;
}

int pop(Pilha* pilha){
    if (vazia(pilha)){
        printf("Pilha vazia\n");
        return 0;
    }

    No* no = pilha->topo;
    int valor = no->valor;
    pilha->topo = no->anterior;

    free(no);

    return valor;
}

int peek(Pilha* pilha){
    if(vazia(pilha)){
        printf("Pilha vazia\n");
        return 0;
    }
    return pilha->topo->valor;
}












