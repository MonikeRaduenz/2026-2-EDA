#include <stdio.h>
#include <stdlib.h>

int main(){
    int n_natural;
    printf("Insira um numero natural:\n");
    scanf("%i", &n_natural);
    if(n_natural != 0 && n_natural != 2 && n_natural != 3 && n_natural != 5 && n_natural != 7){
        if(n_natural%2 == 0 | n_natural%3 == 0 | n_natural%5 == 0 | n_natural%7 == 0 | n_natural == 1){
            printf("Nao!");
        }
        else{
            printf("Sim!");
        }
    }  
    else if(n_natural == 2 | n_natural == 3| n_natural == 5 | n_natural == 7){
        printf("Sim!");
    }
}
