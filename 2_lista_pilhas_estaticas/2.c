#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *vetor;
    int topo;
    int capacidade;
} Pilha;

Pilha *criar(int capacidade){
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->vetor = malloc(capacidade * sizeof(int));
    pilha->topo = 0;
    pilha->capacidade = capacidade;

    return pilha;
}

int vazia(Pilha *pilha){
    return pilha->topo == 0;
}

int cheia(Pilha *pilha){
    return pilha->topo == pilha->capacidade;
}

void pu
h(Pilha *pilha, int valor){

    if (cheia(pilha))
    {
        printf("Pilha cheia\n");
        return;
    }
    pilha->vetor[pilha->topo++] = valor;
}

int pop(Pilha *pilha){
    if (vazia(pilha)){
        printf("Pilha vazia\n");
        return 0;
    }

    return pilha->vetor[--pilha->topo];
}

int main(){
    char palavra[] = "ARARA";
    int n = strlen(palavra);

    Pilha *pilha = criar(n);

    for (int i = 0; i < n; i++){
        push(pilha, palavra[i]);
    }

    for (int i = 0; i < n; i++){
        if (palavra[i] != pop(pilha)){
            printf("Nao e palindromo\n");
            return 0;
        }
    }

    printf("E palindromo\n");
    return 0;
}
