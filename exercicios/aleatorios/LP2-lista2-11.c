#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define linha 10
#define coluna 10

int quantosPixelsNaInt_R(unsigned char *img, unsigned char intensidade, int N);

int main(){

    unsigned char img[linha][coluna], intensidade;
    int cont = 0, quantidade = 0;
    srand(time(NULL));

    printf("digite a intensidade que voce deseja contar: ");
    scanf("%hhu", &intensidade);

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++)
            img[i][j] = rand()%30 + 1;
    }

    quantidade = quantosPixelsNaInt_R(img, intensidade, linha*coluna);

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if(img[i][j] == intensidade){
                cont++;
            }
        }
    }
    if(cont == quantidade) printf("Foi contado com sucesso");
    else printf("Erro ao contar");

    printf("\nespectativa = %d\nrealidade = %d", cont, quantidade);
    
    return 0;
}

int quantosPixelsNaInt_R(unsigned char *img, unsigned char intensidade, int N){
   
    if(N == 0) return 0;

    if(*img == intensidade) return 1 + quantosPixelsNaInt_R(img+1, intensidade, N-1);
    else return quantosPixelsNaInt_R(img+1, intensidade, N-1);   
}