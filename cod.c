#include <stdio.h>
#include <stdlib.h>

void tempo_f(int *horas, int *minutos, int *segundos, int tempo);

int main(){
    int segundos, horas, minutos, tempo;
    printf("Insira o valor em segundos\n");
    scanf("%i", &tempo);
    tempo_f(&horas, &minutos, &segundos, tempo);
    printf("%d:%d:%d", horas, minutos, segundos);
}

void tempo_f(int *horas, int *minutos, int *segundos, int tempo){
    *horas = tempo/3600;
    *minutos = (tempo%3600)/60;
    *segundos = (tempo%3600)%60;
}


// funcao q recebe segundo e transforma em horas e minutos