#include <stdio.h>
#include <stdlib.h>

#define N 3

int main(){
    int m[N][N], soma_p = 0, soma_s = 0;
    printf("Insira os valores da matriz:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%i", &m[i][j]);
        }
    }
    printf("Matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                soma_p += m[i][j];
            }
        }
    }    
    printf("Soma diagonal primaria: %i \n", soma_p);
    for(int i = N; i > 0; i--){
        for(int j = N; j > 0; j--){
            if(i == j){
                soma_s += m[i][j];
            }
        }
    }    
    printf("Soma diagonal secundaria: %i", soma_s);    
}
