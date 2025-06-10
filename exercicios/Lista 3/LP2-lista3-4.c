#include "cabecalhos.h"


int main(){
    int linha, coluna, i, j, flag = 1;
    unsigned char **img;

    printf("Digite linha e coluna\n");
    scanf("%d%d", &linha, &coluna);

    img = geraArray2D(linha, coluna);

    geraImgGreyB_D(img, linha, coluna);

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++)
            if(img[i][j] != 0) flag = 0;  
    }

    if(flag) printf("Deu certo");
    else printf("Deu errado");

    return 0;
}
