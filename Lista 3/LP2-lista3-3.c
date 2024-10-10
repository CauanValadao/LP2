#include "cabecalhos.h"

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
