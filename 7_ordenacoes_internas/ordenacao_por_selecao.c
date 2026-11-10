#include <stdio.h>
#include <stdlib.h>

int* criaVetorMelhorCaso(int n) {
    int* vetor = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        vetor[i] = 0;
    }

    return vetor;
}

int* criaVetorPiorCaso(int n) {
    int* vetor = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        vetor[i] = (n - 1) - i;
    }

    return vetor;
}

int* criaVetorCasoMedio(int n) {
    int* vetor = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % n;
    }

    return vetor;
}

int bubblesort(int v[], int n) {
    int contador = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            contador++;
            if (v[i] > v[j]) {
                contador++;
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    return contador;
}

int main(int argc, char** argv) {
    int n = atoi(argv[1]);

    int* pior = criaVetorPiorCaso(n);
    int* melhor = criaVetorMelhorCaso(n);
    int* medio = criaVetorCasoMedio(n);

    printf("Bubblesort\n");
    printf("Pior caso: %d\n", bubblesort(pior, n));
    printf("Melhor caso: %d\n", bubblesort(melhor, n));
    printf("Caso médio: %d\n", bubblesort(medio, n));
}