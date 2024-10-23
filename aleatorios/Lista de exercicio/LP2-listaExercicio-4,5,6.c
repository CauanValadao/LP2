#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int dia, mes, ano;
}data;

typedef struct{
    double tempMedia;
    data date;
}tempDiaria;

void simulaTemp(tempDiaria *vet, int tam);

double mediaTemp(tempDiaria *vet, int tam);

int main(){
    tempDiaria vet[30];

    simulaTemp(vet, 30);


    for(int i = 0; i < 30; i++){
        printf("DATA %d: %d/%d/%d---temp: %lf\n", i+1, vet[i].date.dia, vet[i].date.mes, vet[i].date.ano, vet[i].tempMedia);
    }
    printf("\n\nmedia: %lf", mediaTemp(vet, 30));
   

    return 0;
}

void simulaTemp(tempDiaria *vet, int tam){
    for(int i = 0; i < tam; i++){
        vet[i].date.ano = 2024;
        vet[i].date.mes = 9;
        vet[i].date.dia = i+1;
        vet[i].tempMedia = rand()/RAND_MAX + rand()%18 + 16;
    }
}

double mediaTemp(tempDiaria *vet, int tam){
    double soma = 0;
    for(int i = 0; i < tam; i ++) soma += vet[i].tempMedia;
    return soma/tam;
}