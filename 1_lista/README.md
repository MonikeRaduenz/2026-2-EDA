1) Escreva uma função que troca os valores entre duas variáveis do tipo float. Faça um 
programa que leia duas variáveis e mostre seus valores na tela. Em seguida, troque os 
valores (usando a função) e mostre novamente os valores.<br>
void troca_valor(float *x, float *y);
2) Faça uma função que calcula o perímetro e a área de um círculo, dado o raio.<br>
void calcula_circulo(float raio, float *pPerimetro, float *pArea);
3) Faça uma função que receba um parâmetro (por valor) com o total de minutos passados 
ao longo do dia e receba também dois parâmetros (referência) no qual deve preencher 
com o valor da hora e do minuto corrente. Faça um programa que leia do teclado quantos 
minutos se passaram desde meia-noite e imprima a hora corrente (use a sua função).<br>
void cacula_hora(int totalMinutos, int *ph, int *pm);
4) Escreva uma função que recebe um vetor e sua capacidade como parâmetros e precisa 
“retornar” o maior e o menor valores do vetor.<br>
void max_min(int vet[], int tam, int *pMin, int *pMax);
5) Escreva um programa que determine o maior valor de um vetor bem como sua posição no 
vetor (índice). Tal processamento deve ser feito em uma função que recebe o vetor (do 
tipo float) e sua capacidade, e “retorna” o maior elemento e sua posição.