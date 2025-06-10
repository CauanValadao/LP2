#include "cabecalhos6.h"

int main(){
   int linha, coluna;
   char nome[80];

    printf("Digite a quantidade de linhas da imagem: ");
    scanf("%d", &linha);
    printf("Digite a quantidade de colunas da imagem: ");
    scanf("%d", &coluna);

    imgGray img = alocaImagemGray(linha, coluna);

    geraImgGrayFull(img, 255);

    printf("Digite o nome da imagem: ");

    scanf("%*c");
    fgets(nome, 80, stdin);
    nome[strcspn(nome, "\n")] = '\0';


    int x = saveImgGrayBin(img, nome);	

    if(!x){
        printf("Erro ao salvar a imagem\n\n");
    }
    else{
        printf("Imagem salva com sucesso\n\n");
    }

    
    imgGray imagem = loadImgGrayBin(nome);
    if(imagem.img == NULL || imagem._img == NULL){
        printf("Erro ao carregar a imagem\n");
    }
    else{
        printf("\n\n");
        for(int i = 0; i < imagem.nLin; i++){
            for(int j = 0; j < imagem.nCol; j++)
                printf("%d ", imagem.img[i][j]);
            printf("\n");
        }
    }
    free(img._img);
    free(img.img);
    free(imagem._img);
    free(imagem.img);
    return 0;
    
}