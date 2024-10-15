#include <stdio.h>
#include <stdlib.h>

unsigned char* alocaImagem1D(int nLin, int nCol);

unsigned char** alocaImagem2D(unsigned char** img1D, int nLin, int nCol);

void geraImgGreyFull_D1(unsigned char* img, int nLin, int nCol, unsigned char pixel);

void geraImgGreyFull_D2(unsigned char** img, int nLin, int nCol, unsigned char pixel);

void geraImgGreyB_D2(unsigned char** img, int nLin, int nCol);

void geraImgGreyB_D1(unsigned char* img, int nLin, int nCol);

void geraImgGreyW_D2(unsigned char** img, int nLin, int nCol);

unsigned char geraPixelGrey(int tipo);

void geraImgGrey_D(unsigned char** img, int nLin, int nCol, int tipo);

int pixelMax_D(unsigned char** img, int nLin, int nCol);

int pixelMin_D(unsigned char** img, int nLin, int nCol);

int* somaPorLinhas_D(unsigned char** img, int nLin, int nCol);

int* somaPorColunas_D(unsigned char** img, int nLin, int nCol);

int somaTotal_R(unsigned char** img, int nLin, int nCol);

int quantosPixelsNaInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten);

int quantosPixelsAbaixoDeInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten);

int quantosPixelsAcimaDeInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten);

#include "procimg.c"