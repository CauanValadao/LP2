#include "cabecalhos6.h"


int main(){
    int linhas, colunas;
    char desc[80];
    
    printf("Digite a quantidade de linhas da imagem: ");
    scanf("%d", &linhas);
    printf("Digite a quantidade de colunas da imagem: ");
    scanf("%d", &colunas);

    imgGray imagem = alocaImagemGray(linhas, colunas);

/*  tRGB pixel;
    pixel.R = 255;
    pixel.G = 255;
    pixel.B = 255;
    */

    geraImgGrayFull(imagem, 255);

    printf("Digite a descricao da imagem: ");

    scanf("%*c");
    fgets(desc, 80, stdin);
    desc[strcspn(desc, "\n")] = '\0';

    int i = saveImgGray(imagem, desc, "imagemteste");

    if(i == 0){
        printf("Erro ao salvar a imagem\n");
    }
    else{
        printf("Imagem salva com sucesso\n");
    }

    char teste[80];

    i = loadHead("imagemteste", teste);

    if(i == 0){
        printf("Erro ao carregar o cabecalho\n");
    }
    else{
        printf("Cabecalho carregado com sucesso\n");
    }

    printf("\nTipo da imagem = %d\ndescricao: %s\n\nfim\n", i, teste);

    imgGray imagemteste = loadImgGray("imagemteste");

    for(int i = 0; i < imagemteste.nLin; i++){
        for(int j = 0; j < imagemteste.nCol; j++)
            printf("%d ", imagemteste.img[i][j]);
        printf("\n");
    }

    free(imagem._img);
    free(imagem.img);
    free(imagemteste._img);
    free(imagemteste.img);
    return 0;
}