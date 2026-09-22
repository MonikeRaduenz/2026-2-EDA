#include <stdio.h>
#include <stdlib.h>

// Estrutura de uma lista duplamente encadeada
typedef struct {
    No *anterior; // ponteiro para o nó anterior da lista
    No *proximo;  // ponteiro para o próximo nó da lista
    void *v;      // conteúdo genérico do nó
} No;
typedef struct {
    No *cabeca;
    No *cauda;
} Lista;

// Inserir um novo elemento no início na lista
void adicionaInicio(Lista *l, void *v, size_t t) {
    No *no = malloc(sizeof(No));

    no->v = malloc(t);
    memcpy(no->v, v, t);
    no->anterior = NULL;
    no->proximo = l->cabeca;
    l->cabeca = no;
    if (l->cauda == NULL) {
        l->cauda = l->cabeca;
    }
}

// Inserir um novo elemento no fim na lista
void adicionaFim(Lista *l, void *v, size_t t) {
    No *no = malloc(sizeof(No));

    no->v = malloc(t);
    memcpy(no->v, v, t);
    no->anterior = l->cauda;
    no->proximo = NULL;
    l->cabeca = no;
    if (l->cabeca == NULL) {
        l->cabeca = l->cauda;
    }
}

// Inserir um novo elemento no fim na lista
void percorrer(Lista *l) {
    No *no = l->cabeca;

    while (no != NULL) {
        // visita no
        printf("% p", no->v);
        no = no->proximo;
    }
}

// Operação de percorrer genérica com suporte a callback
void percorre(Lista *l, void(callback)(void *))
{
    No *no = l->cabeca;

    while (no != NULL) {
        callback(no->v);

        no = no->proximo;
    }
}

// Operação de percorrer sendo chamada pela aplicação
void meuCallback(void *v) {
    float *f = (float *)v;
    printf("%f\n", f);
}
int main() {
    Lista *l = cria();
    // Insere dados na lista
    percorre(l, meuCallback); // passando a função como parâmetro
}
