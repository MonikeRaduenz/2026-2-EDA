#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct{
    int cabeca, cauda; // posição atual da cabeça e da cauda da fila
    int v[MAX];        // vetor contendo o conteúdo da fila
} Fila;
