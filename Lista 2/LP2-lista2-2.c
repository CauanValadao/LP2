#include <stdio.h>

#define linha 100
#define coluna 100

int N = linha * coluna;

void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel);

int main(){
    unsigned char img[linha][coluna] = {0}, pixel;
    int i, j, soma = 0;
    
    printf("Digite o valor do pixel: ");
    scanf("%hhu", &pixel);

    geraImgGreyFull_R(img, pixel);


    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            if(img[i][j] == pixel) soma++;
        }
    }

    if(soma != linha*coluna) printf("erro");
    else printf("deu certo");

    
    return 0;
}

void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel){
    if(N == 0){
        N = linha * coluna;
        return;
    }
    N--;
    img[0][0] = pixel;
    geraImgGreyFull_R(&img[0][1], pixel);
}