#include <stdio.h>
#include <stdlib.h>

// Definição de pilhas a partir de estruturas
#define MAX 10
typedef struct {
    int topo;   // posição atual do vetor (topo)
    int v[MAX]; // vetor contendo o conteúdo da pilha
} Pilha;

// Criar uma nova pilha
Pilha *cria() {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = 0; // inicializa a posição atual com zero
    return p;
}

// Inserir um novo elemento na pilha
void push(Pilha *p, int v) {
    if (p->topo == MAX) {
        printf("Capacidade máxima da pilha foi alcançada");
        exit(-1);
    } else {
        p[p->topo++] = v; // insere elemento na próxima posição livre
    }
}

// Verificar se a pilha está vazia
int vazia(Pilha *p) {
    return p->topo == 0;
}

// Remover elemento do topo na pilha
int pop(Pilha *p) {
    int v;

    if (vazia(p)) {
        printf("Pilha vazia");
        exit(-1);
    } 
    else {
        v = p[p->topo--]; // recupera valor do topo
    }
    return v;
}

// Libera memória da pilha
void limpa(Pilha *p) {
    if (p != NULL) {
        free(p);
    }

    p = NULL;
}

// Visitar todos os elementos da pilha
void percorre(Pilha *p) {
    while (vazia(p)) {
        int v = pop(p);

        printf("%d", v);
    }
}
