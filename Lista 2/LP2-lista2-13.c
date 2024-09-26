#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define linha 100
#define coluna 100

int quantosPixelsAcimaDeInt_R(unsigned char img[linha][coluna], unsigned char inteiro); //funcao que retorna a quantidade de pixels acima de um inteiro

int main(){
    unsigned char img[linha][coluna];
    int i, j, x, maior = 0, acima;
    srand(time(NULL));

    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            img[i][j] = rand() % 256;
        }
    }
    printf("Digite um valor inteiro: ");
    scanf("%d", &x);

    acima = quantosPixelsAcimaDeInt_R(img, x);

    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            if(img[i][j] > x) maior++;
        }
    }
    if(maior == acima) printf("A funcao esta correta\n");
    else printf("A funcao esta incorreta\n");

    return 0;
}
int quantosPixelsAcimaDeInt_R(unsigned char img[linha][coluna], unsigned char inteiro){
    return linha*coluna - quantosPixelsAbaixoDeInt_R(img, inteiro) - quantosPixelsNaInt(img, inteiro);
}
