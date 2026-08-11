#include <stdio.h>
#include <stdlib.h>

#define N 4

// multiplicar todos menos o indice

int main(){
    int v[N], v2[N];
    printf("Insira os valores para o vetor:\n");
    for(int i = 0; i < N; i++){
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < N; i++) { 
        int produto = 1; 
        for (int j = 0; j < N; j++) { 
            if (j != i) { 
                produto *= v[j]; 
                } 
            } 
        v2[i] = produto; 
        } 
    printf("[");
    for (int i = 0; i < N; i++) { 
        printf("%d ", v2[i]); 
    }
    printf("]");
}