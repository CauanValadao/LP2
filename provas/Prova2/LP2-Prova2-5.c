#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char uchar;

typedef struct{
    uchar R, G, B;
}tRGB;

typedef struct{
    uchar *_img;
    uchar **img;
    int nLin, nCol;
}imgGray;

typedef struct{
    tRGB *_img;
    tRGB **img;
    int nLin, nCol;
}imgRGB;

struct imagens{
    imgGray img;
    struct imagens *prox;
};

typedef struct imagens tImagens;
imgGray convert(imgRGB img);
int geraImgRGBFull(imgRGB img, tRGB pixel);
imgRGB alocaImagemRGB(int nLin, int nCol);

int main(){
    int nLin, nCol, i, erro = 0;
    uchar teste;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &nLin);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &nCol);

    imgRGB img = alocaImagemRGB(nLin, nCol);
    tRGB pixel = {0,0,0};

    geraImgRGBFull(img, pixel);

    imgGray imagem = convert(img);

    for(i = 0; i < nCol*nLin; i++){
        teste = (uchar)(0.299 * img._img[i].R + 0.587 * img._img[i].G + 0.114 * img._img[i].B);
        if(teste) erro = 1;
    }
    if(erro) printf("Erro no elemento (%d,%d)", i/nLin, i%nLin);
    else printf("tudo certo(todos os elementos da imagem criada foram iguais a 0)");

    free(img._img);
    free(img.img);
    free(imagem._img);
    free(imagem.img);

    return 0;
}

imgRGB alocaImagemRGB(int nLin, int nCol){
    imgRGB imagem;
    imagem.nLin = nLin;
    imagem.nCol = nCol;

    imagem._img = (tRGB*)malloc(sizeof(tRGB)*nLin*nCol);
    if(imagem._img == NULL){
        imagem.img = NULL;
        return imagem;
    }

    imagem.img = (tRGB**)malloc(sizeof(tRGB*)*nLin);
    if(imagem.img == NULL){
        free(imagem._img);
        imagem._img = NULL;
        return imagem;
    }

    for(int i = 0; i < nLin; i++){
        imagem.img[i] = &imagem._img[i*nCol];
    }

    return imagem;
}

int geraImgRGBFull(imgRGB img, tRGB pixel){
    if(img.img == NULL || img._img == NULL) return 0;

    for(int i = 0; i < img.nCol*img.nLin; i++){
        img._img[i].R = pixel.R;
        img._img[i].G = pixel.G;
        img._img[i].B = pixel.B;
    }

    return 1;
}

imgGray convert(imgRGB img){
    imgGray imgcinza;

    if(img.img == NULL || img._img == NULL){
        imgcinza.img = NULL;
        imgcinza._img = NULL;
        return imgcinza;
    }
    
    imgcinza.nLin = img.nLin;
    imgcinza.nCol = img.nCol;
    
    imgcinza._img = (uchar*)malloc(sizeof(uchar)*img.nLin*img.nCol);
    if(imgcinza._img == NULL){
        imgcinza.img = NULL;
        return imgcinza;
    }

    imgcinza.img = (uchar**)malloc(sizeof(uchar*)*img.nLin);
    if(imgcinza.img == NULL){
        free(imgcinza._img);
        imgcinza._img = NULL;
        return imgcinza;
    }

    for(int i = 0; i < img.nLin; i++){
        imgcinza.img[i] = &imgcinza._img[i*img.nCol];
    }
    
    for(int i = 0; i < img.nLin * img.nCol; i++)
        imgcinza._img[i] = ((uchar)(0.299 * img._img[i].R + 0.587 * img._img[i].G + 0.114 * img._img[i].B));

    return imgcinza;

}