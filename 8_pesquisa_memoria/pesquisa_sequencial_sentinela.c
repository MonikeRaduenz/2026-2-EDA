#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Necessário para inicializar o srand

// Aloca n + 1 posições para garantir espaço para o sentinela
int* criaVetor(int n) {
    int* v = malloc(sizeof(int) * (n + 1)); 
    
    for (int i = 0; i < n; i++) {
        v[i] = rand() % n;
    }

    return v;
}

int pesquisaSequencialSentinela(int chave, int v[], int n) {
    int contador = 1;
    int i = 0;
    
    v[n] = chave; // Coloca o sentinela na última posição (índice n)
    
    while (v[i] != chave) {
        contador++; // Conta a verificação do loop
        i++;
    }
    
    contador++; // Conta a verificação que fez o loop parar
    
    // Se i < n, o elemento foi encontrado dentro do vetor original
    if (i < n) {
        // Opcional: retornar o contador de operações em vez do índice, 
        // seguindo o padrão do seu código anterior que retorna métricas de custo.
        return contador; 
    }
    
    return contador; // Caso tenha parado no sentinela (não encontrado)
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Uso: %s <tamanho_do_vetor>\n", argv[0]);
        return 1;
    }

    srand(time(NULL)); // Inicializa a semente aleatória para o rand()

    int n = atoi(argv[1]);
    int* v = criaVetor(n);

    printf("Pesquisa Sequencial com Sentinela\n");
    printf("Melhor caso: %d\n", pesquisaSequencialSentinela(v[0], v, n));
    printf("Pior caso: %d\n", pesquisaSequencialSentinela(n + 999, v, n)); // Garante um valor que não está no vetor
    printf("Caso medio: %d\n", pesquisaSequencialSentinela(v[rand() % n], v, n));

    free(v); // Boa prática: liberar a memória alocada
    return 0;
}