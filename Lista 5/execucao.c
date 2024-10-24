#include "cabecalhos.h"



int main(){
    imgGray imagem;
    imagem = alocaImagemGray(100,100);
    int i, teste = 0;

    if(imagem._img == NULL || imagem.img == NULL)
         printf("Execucao da funcao 1 falhou");
     else
        printf("Execucao da funcao 1 teve exito");

    
    geraImgGrayFull(imagem, 0);

    for(i = 0; i < imagem.nCol*imagem.nLin; i++) if(!imagem._img[i]) teste = 1;

    if(teste)
        printf("Execucao da funcao 2 falhou");
    else
        printf("Execucao da funcao 2 teve exito");   

   
    free(imagem._img);
    free(imagem.img);

    imgRGB imagemrgb;

    imagemrgb = alocaImagemRGB(30,30);

    if(imagemrgb._img == NULL || imagemrgb.img == NULL)
        printf("Execucao da funcao 1 falhou");
    else
        printf("Execucao da funcao 1 teve exito");

    free(imagemrgb._img);
    free(imagemrgb.img);


    return 0;
}