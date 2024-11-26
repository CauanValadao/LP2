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

imgRGB geraRandomImage(int nLin, int nCol);

int main(){
    int nLin, nCol, i, j;
    srand(time(NULL));

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &nLin);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &nCol);

    imgRGB imagem = geraRandomImage(nLin, nCol);

    if(imagem.img == NULL){
        printf("Erro de alocacao");
        return 0;
    }

    for(i = 0; i < nLin; i++){
        printf("\n");
        for(j = 0; j < nCol; j++)
            printf("%d ", imagem.img[i][j].R);
    }

    free(imagem._img);
    free(imagem.img);

    return 0;
}

imgRGB geraRandomImage(int nLin, int nCol){
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

    for(int i = 0; i < nLin*nCol; i++){
        imagem._img[i].R = rand()%256;
        imagem._img[i].G = rand()%256;
        imagem._img[i].B = rand()%256;
    }

    return imagem;
}