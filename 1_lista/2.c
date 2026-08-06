#include <stdio.h>
#include <stdlib.h>

void calcula_circulo(float raio, float *pPerimetro, float *pArea);

int main(){
    float raio, *pPerimetro, *pArea, perimetro, area;
    printf("Insira o valor do raio:\n");
    scanf("%f", &raio);
    pArea = &area;
    pPerimetro = &perimetro;
    calcula_circulo(raio, pPerimetro, pArea);
    printf("Valor do perimetro: %f \n", *pPerimetro);
    printf("Valor da area: %f", *pArea);
}

void calcula_circulo(float raio, float *pPerimetro, float *pArea){
    *pPerimetro = raio * 3.14;
    *pArea = (raio * raio) * 3.14;
}
