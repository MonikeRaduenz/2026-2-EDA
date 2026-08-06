#include <stdio.h>
#include <stdlib.h>

void troca_valor(float *x, float *y);

float main(){
    float a, b, *x, *y;
    printf("Insira valor para x:\n");
    scanf("%f", &a);
    x = &a;
    printf("Insira valor para y:\n");
    scanf("%f", &b);
    y = &b;
    troca_valor(x, y);
    printf("Valores novos:\n x - %f \n y - %f", a, b);
}

void troca_valor(float *x, float *y){
    float aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
