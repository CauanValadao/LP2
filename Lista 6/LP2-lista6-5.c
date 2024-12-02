#include "cabecalhos6.h"

int main(){
    int linhas, colunas;
    char desc[80];
    
    printf("Digite a quantidade de linhas da imagem: ");
    scanf("%d", &linhas);
    printf("Digite a quantidade de colunas da imagem: ");
    scanf("%d", &colunas);

    imgRGB imagem = alocaImagemRGB(linhas, colunas);
    tRGB pixel;
    pixel.R = 255;
    pixel.G = 255;
    pixel.B = 255;

    geraImgRGBFull(imagem, pixel);

    scanf("%*c");
    printf("Digite a descricao da imagem: ");
    fgets(desc, 80, stdin);
    desc[strcspn(desc, "\n")] = '\0';

    int x = saveImgRGB(imagem, desc, "Lista6_5_teste");

    if(!x){
        printf("erro ao salvar a imagem\n");
    }

    char teste[80];
    x = loadHead("Lista6_5_teste", teste);

    if(strcmp(teste, desc) || x != 2){
        printf("erro ao carregar o cabecalho");
    }

    imgRGB img = loadImgRGB("Lista6_5_teste");

    if(img.img == NULL || img._img == NULL){
        printf("erro ao carregar a imagem\n");
    }

    for(int i = 0; i < img.nLin; i++){
        for(int j = 0; j < img.nCol; j++)
            printf("%d ", img.img[i][j].R);
        printf("\n");
    }

    free(imagem._img);
    free(imagem.img);
    free(img._img);
    free(img.img);

    return 0;
}