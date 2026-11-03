#include <stdio.h>
#include <stdlib.h>

// A função agora usa um ponteiro para armazenar e retornar o número de iterações
int pesquisaSequencial(int chave, int v[], int n, int *iteracoes) {
    int i;
    *iteracoes = 0; // Inicializa o contador

    for (i = 0; i < n; i++) {
        (*iteracoes)++; // Incrementa a cada tentativa/iteração no loop
        
        if (v[i] == chave) {
            return i; // Retorna o índice onde o elemento foi encontrado
        }
    }
    
    return -1; // Retorna -1 se o elemento não estiver no vetor
}

int main() {
    int vetor[] = {10, 25, 30, 45, 50, 75};
    int tamanho = 6;
    int chaveBusca = 45;
    int iteracoes = 0;

    int resultado = pesquisaSequencial(chaveBusca, vetor, tamanho, &iteracoes);

    if (resultado != -1) {
        printf("Elemento %d encontrado no índice %d.\n", chaveBusca, resultado);
    } else {
        printf("Elemento %d não encontrado no vetor.\n", chaveBusca);
    }
    
    printf("Número de iterações necessárias: %d\n", iteracoes);

    return 0;
}