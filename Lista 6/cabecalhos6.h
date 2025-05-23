#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int saveImgGray(imgGray img, char* desc, char* fileName);

int saveImgRGB(imgRGB img, char* desc, char* fileName);

int loadHead(char* fileName, char* desc);

imgGray loadImgGray(char* fileName);

imgRGB loadImgRGB(char* fileName);

int saveImgGrayBin(imgGray img, char* fileName);

int saveImgRGBBin(imgRGB img, char* fileName);

imgGray loadImgGrayBin(char* fileName);

imgRGB loadImgRGBBin(char* fileName);

/*-------------------------------------------------------*/

imgGray alocaImagemGray(int nLin, int nCol);

imgRGB alocaImagemRGB(int nLin, int nCol);

int geraImgGrayFull(imgGray img, uchar pixel);

int geraImgRGBFull(imgRGB img, tRGB pixel);

int geraImgGrayB(imgGray img);

int geraImgRGBB(imgRGB img);

int geraImgGrayW(imgGray img);

int geraImgRGBW(imgRGB img);

unsigned char geraPixelGrey(int tipo);

int geraImgGray(imgGray img, int tipo);

int geraImgRGB(imgRGB img, int tipo);

int pixelGrayMax(imgGray img);

int pixelGrayMin(imgGray img);

tRGB pixelRGBMax(imgRGB img);

tRGB pixelRGBMin(imgRGB img);

int* somaPorLinhasGray(imgGray img);

int* somaPorColunasGray(imgGray img);

#include "funcoes6.c"