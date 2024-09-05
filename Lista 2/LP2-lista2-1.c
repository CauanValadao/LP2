#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraLinhaR(unsigned char lin[640], int tipo);

unsigned char geraGreyPixel(int tipo);

int main(){
    unsigned char lin[640];
    int tipo, maior = 0, menor = 0;
    srand(time(NULL));

    printf("Digite qual tipo voce deseja: ");
    scanf("%d", &tipo);

    geraLinhaR(lin, tipo);

    for(int i = 0; i < 640; i++){
        if(lin[i] > 127) maior++;
        else menor++;
    }
    printf("Quantidade de pixels com intensidade maior que 127: %d\n", maior);
    printf("Quantidade de pixels com intensidade menor que 127: %d\n", menor);
    return 0;
}

void geraLinhaR(unsigned char lin[640], int tipo){
    for(int i = 0; i < 640; i++) lin[i] = geraGreyPixel(tipo);
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


