#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define linha 100
#define coluna 100

unsigned char pontoEquilibrio(unsigned char img[linha][coluna]);

int main() {
    unsigned char img[linha][coluna];
    int i, j;
    srand(time(NULL));

    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            img[i][j] = rand() % 256;
        }
    }

    printf("Ponto de equilibrio: %d\n", pontoEquilibrio(img));

    return 0;
}

unsigned char pontoEquilibrio(unsigned char img[linha][coluna]) {
    
}

