#include <stdio.h>
#include <stdlib.h>

int pesquisaBinaria(int chave, int v[], int n){
    int inicio = 0, meio, fim = n – 1;
    while (inicio <= fim){
        meio = (inicio + fim) / 2;
        if (chave == v[meio]){
            return meio;
        }
        else if (chave < v[meio]){
            fim = meio - 1;
        }
        else{
            inicio = meio + 1;
        }
    }
    return -1; // Índice impossível
}

int pesquisaBinaria(int chave, int v[], int n){
    int inicio = 0, meio, fim = n – 1;
    while (inicio <= fim){
        meio = (inicio + fim) / 2;
        if (chave == v[meio]){
            return meio;
        }
        else if (chave < v[meio]){
            fim = meio - 1;
        }
        else{
            inicio = meio + 1;
        }
    }
    return -1; // Índice inválido
}
