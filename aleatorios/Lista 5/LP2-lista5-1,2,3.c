#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
}data;

void solicitarData(data* date);

int comparaDatas(data d1, data d2);

void geraData(data* date);

void ordenaVetor(data* vet, int tam);

int main(){
    //data aniversario, aniversario2;
    data vet[10];
    srand(time(NULL));

    for(int i = 0; i < 10; i++) geraData(&vet[i]);

    ordenaVetor(vet, 10);


    /*solicitarData(&aniversario);
    solicitarData(&aniversario2);

    printf("%d",comparaDatas(aniversario, aniversario2));*/
    for(int i = 0; i < 10; i++){
        printf("DATA %d: %d/%d/%d\n", i+1, vet[i].dia, vet[i].mes, vet[i].ano);
    }

    return 0;
}

void solicitarData(data* date){
    printf("Digite seu dia de nascimento: ");
    scanf("%d", &date->dia);
    printf("Digite seu mes de nascimento: ");
    scanf("%d", &date->mes);
    printf("Digite seu ano de nascimento: ");
    scanf("%d", &date->ano);
}

int comparaDatas(data d1, data d2){
    if(d1.ano == d2.ano){
        if(d1.mes == d2.mes){
            if(d1.dia == d2.dia) return 0;

            if(d1.dia < d2.dia) return -1;
        }
        else if(d1.mes < d2.mes) return -1;
    }
    if(d1.ano < d2.ano) return -1;

    return 1;
}

void geraData(data* date){
    date->dia = rand()%31 + 1;
    date->mes = rand()%12 + 1;
    date->ano = 2023;
}

void ordenaVetor(data* vet, int tam){
    data temp;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam - i; j++){
            if(comparaDatas(vet[j], vet[j+1]) == 1){
                temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }
}