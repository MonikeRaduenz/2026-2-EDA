#include <stdio.h>
#include <stdlib.h>

void calcula_circulo(float *x, float *y);

int main(){
    float a, b, *x, *y;
    printf("Insira valor para x:\n");
    scanf("%f", &a);
    x = &a;
    printf("Insira valor para y:\n");
    scanf("%f", &b);
    y = &b;
    calcula_circulo(x, y);
    printf("Valores novos:\n x - %f \n y - %f", a, b);
}

void calcula_circulo(float *x, float *y){

}
