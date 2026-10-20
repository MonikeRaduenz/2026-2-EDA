#include <stdio.h>
#include <stdlib.h>

// Declaração antecipada da função swap para evitar avisos de compilação
void swap(int v[], int i, int j);

void heapify(int v[], int n, int i){
    int raiz = i;
    int esquerda = 2 * i + 1; // Corrigido o operador *
    int direita = 2 * i + 2;  // Corrigido o operador *

    if (esquerda < n && v[esquerda] > v[raiz])
        raiz = esquerda; // Troca esquerda com raiz
    if (direita < n && v[direita] > v[raiz])
        raiz = direita; // Troca direita com raiz

    if (raiz != i){                         // Verifica se a raiz precisa ser alterada
        swap(v, i, raiz);   // Realiza a troca
        heapify(v, n, raiz); // Garante recursivamente o heap máximo
    }
}

// vai trocar os valores maiores pelos menores
void swap(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void heapsort(int v[], int n){
    // Cria o heap máximo a partir dos nós não folha (n / 2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--){ // Corrigido o sinal de menos (-)
        heapify(v, n, i);
    }

    // Recria o heap máximo reduzindo o tamanho da heap a cada iteração
    for (int i = n - 1; i > 0; i--){ // Corrigido o sinal de menos (-)
        swap(v, 0, i); // Troca o primeiro valor (maior) pelo último da heap parcial

        heapify(v, i, 0); // Atualiza o heap máximo parcial
    }
}

int main(){
    int v[3] = {10, 50, 30};
    int n = 3;
    
    heapsort(v, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
    
    return 0;
}