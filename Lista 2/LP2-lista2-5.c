#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define linha 100
#define coluna 100

void geraImgGrey_R(unsigned char *img, int tipo, int N);
unsigned char geraGreyPixel(int tipo);

int main(){
    unsigned char img[linha][coluna];
    int cont = 0, tipo, maior = 0, menor = 0;
    srand(time(NULL));

    printf("Digite o tipo de pixel que deseja: ");
    scanf("%d", &tipo);	

    geraImgGrey_R(img, tipo, linha*coluna);
    

    for(int i = 0; i < linha; i++){           
        for(int j = 0; j < coluna; j++){ 
            cont++;  
            if(img[i][j] > 127) maior++;
            else menor++;         
        }
    }

    if(linha * coluna == cont) printf("\n\nImagem gerada com sucesso!\n");     //linha * coluna representa a quantidade de pixels da imagem, que deve ser igual a cont
    else printf("\n\nErro na geracao da imagem!\n");

    printf("Quantidade de pixels com intensidade maior que 127: %d\n", maior);	
    printf("Quantidade de pixels com intensidade menor que 127: %d\n", menor);

    return 0;
}

void geraImgGrey_R(unsigned char *img, int tipo, int N){
    if(N == 0) return;    
    *img = geraGreyPixel(tipo);          
    geraImgGrey_R(img + 1, tipo, N-1);
}

//codigo de vinicius
unsigned char geraGreyPixel(int tipo){
    int valor;
    int proba= rand() % 100; //gera um número entre 0 e 100;
    if(tipo<0){
       if(proba < 80){      //80% de gerar um número entre 0 e 127.
            valor= rand() % 128;
       }else{               //20% de gerar um número de qualquer intensidade.
            valor= rand() % 256;
        }
    }else if(tipo>0){
        if(proba < 80){     //80% de gerar um número entre 128 e 255.
            valor = 128 + rand() % 128;
        }else{
            valor = rand() % 256; //20% de gerar um número de qualquer intensidade.
        }
    }else{
        valor = rand() % 256; //gera um número entre 0 e 255.
    }
return (unsigned char) valor;
}