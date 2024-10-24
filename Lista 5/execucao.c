#include "cabecalhos.h"

int main(){
    imgGray imagemC;
    imgRGB imagemCrgb;
    int i, teste = 0;

    //funcao 1
    imagemC = alocaImagemGray(10,10);
    if(imagemC._img == NULL || imagemC.img == NULL)
         printf("Execucao da funcao 1 falhou");
    else
        printf("Execucao da funcao 1 teve exito");

    //funcao 2
    imagemCrgb = alocaImagemRGB(30,30);
    if(imagemCrgb._img == NULL || imagemCrgb.img == NULL)
        printf("\nExecucao da funcao 2 falhou");
    else
        printf("\nExecucao da funcao 2 teve exito");

    //funcao 3
    geraImgGrayFull(imagemC, 0);

    for(i = 0; i < imagemC.nCol*imagemC.nLin; i++) if(imagemC._img[i]) teste = 1;

    if(teste)
        printf("\nExecucao da funcao 3 falhou");
    else
        printf("\nExecucao da funcao 3 teve exito");   

    //funcao 6
    geraImgRGBB(imagemCrgb);

    teste = 0;

    for(i = 0; i < imagemCrgb.nCol*imagemCrgb.nLin; i++) if(imagemCrgb._img[i].R || imagemCrgb._img[i].G || imagemCrgb._img[i].B) teste = 1;

    if(teste)
        printf("\nExecucao da funcao 6 falhou");
    else
        printf("\nExecucao da funcao 6 teve exito");


    //funcao 7
    geraImgGrayW(imagemC);

    teste = 0;
    for(i = 0; i < imagemC.nCol*imagemC.nLin; i++) if(imagemC._img[i] != 255) teste = 1;
    if(teste)
        printf("\nExecucao da funcao 7 falhou");
    else
        printf("\nExecucao da funcao 7 teve exito");

    //funcao 8

    geraImgRGBW(imagemCrgb);

    teste = 0;
    for(i = 0; i < imagemCrgb.nCol*imagemCrgb.nLin; i++) if(imagemCrgb._img[i].R != 255 || imagemCrgb._img[i].G != 255 || imagemCrgb._img[i].B != 255) teste = 1;
    if(teste)
        printf("\nExecucao da funcao 8 falhou");
    else
        printf("\nExecucao da funcao 8 teve exito");
    
    //funcao 9
    geraImgGray(imagemC, 1);
    int maior = 0, menor = 0;
    teste = 0;

    for(i = 0; i < imagemC.nCol*imagemC.nLin; i++){
        if(imagemC._img[i] >= 128) maior++;
        else menor++;
    }
    if(maior < menor) teste = 1;
    
    if(teste)
        printf("\nExecucao da funcao 9 falhou");
    else
        printf("\nExecucao da funcao 9 teve exito");

    //funcao 10
    geraImgRGB(imagemCrgb, 1);
    maior = 0;
    menor = 0;
    teste = 0;

    for(i = 0; i < imagemCrgb.nCol*imagemCrgb.nLin; i++){
        if(imagemCrgb._img[i].R >= 128) maior++;
        else menor++;
        if(imagemCrgb._img[i].G >= 128) maior++;
        else menor++;
        if(imagemCrgb._img[i].B >= 128) maior++;
        else menor++;
    }
    if(maior < menor) teste = 1;

    if(teste)
        printf("\nExecucao da funcao 10 falhou");
    else
        printf("\nExecucao da funcao 10 teve exito");
        
    //funcao 13
    geraImgGrayFull(imagemC, 1);

    int* vet;

    vet = somaPorLinhasGray(imagemC);

    teste = 0;

    for(i = 0; i < imagemC.nLin; i++) if(vet[i] != imagemC.nLin*1) teste = 1;
        
    if(teste)
        printf("\nExecucao da funcao 13 falhou\n");
    else
        printf("\nExecucao da funcao 13 teve exito\n");
      
   
    free(imagemC._img);
    free(imagemC.img);
    free(imagemCrgb._img);
    free(imagemCrgb.img);
    free(vet);
    return 0;
}