#define linha 20
#define coluna 20
#include <stdlib.h>

int quantosPixelsAcimaDeInt_R(unsigned char img[linha][coluna], unsigned char int);
int quantosPixelsAbaixoDeInt_R(unsigned char img[linha][coluna], unsigned char int);

unsigned char pontoEquilibrio(unsigned char img[linha][coluna]);
unsigned char pontoEquilibrio_aux(unsigned char img[linha][coluna],int menor, int n);

unsigned char pontoEquilibrio(unsigned char img[linha][coluna]){
    menor = quantosPixelsAcimaDeInt_R(img, 0);
    return pontoEquilibrio_aux(img, menor, 1);
 }

unsigned char pontoEquilibrio_aux(unsigned char img[linha][coluna], int menor, int n){
    int x = abs(quantosPixelsAcimaDeInt_R(img, n) - quantosPixelsAbaixoDeInt_R(img, n));
    if(x < menor) menor = n;
    if(n == 255) return menor;
    pontoEquilibrio_aux(img, menor, n+1);
}