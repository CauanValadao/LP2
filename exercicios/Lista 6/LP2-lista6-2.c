#include "cabecalhos6.h"
#include <string.h>



int saveImgRGB(imgRGB img, char[] fileName){
    if(img.img == NULL || img._img == NULL){
        return 0;
    }

    char* nome = (char*)malloc(sizeof(char)*strlen(fileName) + 5);
    
    if(nome ==  NULL){
        printf("Erro ao alocar memoria\n");
        return 0;
    }
    strcpy(nome, fileName);
    strcat(nome, ".img");

    char* nome2 = (char*)malloc(sizeof(char)*strlen(fileName) + 5);

    if(nome2 == NULL){
        printf("Erro ao alocar memoria\n");
        free(nome);
        return 0;
    }
    strcpy(nome2, fileName);
    strcat(nome2, ".txt");
    
    /*--------------------------------------------------------------*/

    FILE *imagem = fopen(nome, "wb");
    
    if(imagem == NULL){
        printf("Erro ao abrir o arquivo imagem\n");
        return 1;
        free(nome);
        free(nome2);
    }
    else{
        printf("Arquivo imagem aberto com sucesso\n");
    }

    fwrite(img._img, sizeof(tRGB), img.nCol*img.nLin, imagem);

    fclose(imagem);
    
    /*--------------------------------------------------------------*/

    FILE *hed = fopen(nome2, "w");

    if(hed == NULL){
        printf("Erro ao abrir o arquivo hed\n");
        return 1;
        free(nome);
        free(nome2);
    }
    else{
        printf("Arquivo hed aberto com sucesso\n");
    }
    
    int i = fputs("RGB\n", hed);

    if(i == EOF){
    printf("Erro ao escrever no arquivo\n");
    fclose(hed);
    return 0;
    }

    fprintf(hed, "%d\n%d\n%s\n%s\n", img.nLin, img.nCol, desc, nome);

    fclose(hed);
    free(nome);
    free(nome2);

    return 1;
}