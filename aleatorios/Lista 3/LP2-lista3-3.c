#include <stdlib.h>
#include <stdio.h>

void geraImgGreyFull_D(unsigned char** img, int nLin, int nCol, unsigned char pixel);

unsigned char** geraArray2D(int nLin, int nCol);

int main(){
    int linha, coluna, i, j, soma = 0;
    unsigned char pixel = 90, **img;

    printf("Digite linha e coluna\n");
    scanf("%d%d", &linha, &coluna);

    

    img = geraArray2D(linha, coluna);
   

    geraImgGreyFull_D(img, linha, coluna, pixel);

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++)
            soma += img[i][j];
    }

    if(soma == linha*coluna*pixel) printf("deu certo");
    else printf("deu errado");
    
    for(i = 0; i < linha; i++){
        free(img[i]);
    }
    free(img);
    
    return 0;
}

void geraImgGreyFull_D(unsigned char **img, int nLin, int nCol, unsigned char pixel){
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            img[i][j] = pixel;
        }
    }
}
unsigned char** geraArray2D(int nLin, int nCol){
    unsigned char **mat;
    mat = (unsigned char**)malloc(sizeof(unsigned char*)*nLin);
    for(int i = 0; i < nLin; i++){
        mat[i] = (unsigned char*)malloc(sizeof(unsigned char)*nCol);
    }
    return mat;
}
