#include <stdlib.h>
#include <stdio.h>

unsigned char geraGreyPixel (int tipo);

unsigned char* geraArray1D(int tam);

unsigned char** geraArray2D(int nLin, int nCol);

void geraImgGreyFull_D(unsigned char **img, int nLin, int nCol, unsigned char pixel);

void geraImgGreyB_D(unsigned char** img, int nLin, int nCol);

void geraImgGreyW_D(unsigned char** img, int nLin, int nCol);

void geraImgGrey_D(unsigned char** img, int nLin, int nCol, int tipo);

int pixelMax_D(unsigned char** img, int nLin, int nCol);

int pixelMin_D(unsigned char** img, int nLin, int nCol);

int* somaPorLinhas_D(unsigned char** img, int nLin, int nCol);

int* somaPorColunas_D(unsigned char** img, int nLin, int nCol);

int somaTotal_R(unsigned char** img, int nLin, int nCol);

int quantosPixelsNaInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten);

int quantosPixelsAbaixoDeInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten);

#include "funcoes.c"