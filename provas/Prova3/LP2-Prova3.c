#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int guardaImagem(unsigned char** img, int  lin, int col, char* fileName){
    if(fileName == NULL || img == NULL || lin <= 0 || col <= 0){
        return 0;
    }
    FILE *imagem = fopen(fileName, "wb");
    if(imagem == NULL){
        return 0;
    }
    if(fwrite(&lin, sizeof(int), 1, imagem) != 1){
        fclose(imagem);
        return 0;
    }

    if(fwrite(&col, sizeof(int), 1, imagem) != 1){
        fclose(imagem);
        return 0;
    }
    
   for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(fwrite(&img[i][j], sizeof(unsigned char), 1, imagem) != 1){
                fclose(imagem);
                return 0;
            }
        }
   }
          
    fclose(imagem);
    return 1;
}

unsigned char** carregaImagem(int* col, int* lin, char* fileName){
    if(fileName == NULL || col == NULL || lin == NULL){
        return NULL;
    }
    FILE *imagem = fopen(fileName, "rb");
    if(imagem == NULL){
        return NULL;
    }
    if(fread(lin, sizeof(int), 1, imagem) != 1){
        fclose(imagem);
        return NULL;
    }
    if(fread(col, sizeof(int), 1, imagem) != 1){
        fclose(imagem);
        return NULL;
    }
    unsigned char** img = (unsigned char**)malloc(sizeof(unsigned char*)*(*lin));
    if(img == NULL){
        fclose(imagem);
        return NULL;
    }
    for(int i = 0; i < *lin; i++){
        img[i] = (unsigned char*)malloc(sizeof(unsigned char)*(*col));
        if(img[i] == NULL){
            for(int j = 0; j < i; j++){
                free(img[j]);
            }
            free(img);
            fclose(imagem);
            return NULL;
        }
    }

    for(int i = 0; i < *lin; i++){
        if(fread(img[i], sizeof(unsigned char), *col, imagem) != (unsigned char)*col){
            for(int j = 0; j < i; j++){
                free(img[j]);
            }
            free(img);
            fclose(imagem);
            return NULL;
        }
    }
    fclose(imagem);
    return img;
}

int quantcaracteres(char* fileName){
    if(fileName == NULL)
        return -1;
    
    int soma = 0;
    char buffer[1201];

    FILE *arq = fopen(fileName, "r");
    if(arq == NULL){
        fclose(arq);
        return -1;
    }
    
    while(fgets(buffer, 1200, arq) != NULL){
        soma += strlen(buffer);
    }
    fclose(arq);

    if(soma > 1200)
        return 0;
    else
        return soma;

}

int main(){
    int i, j, x = 0, lin, col;

    printf("Questao 3,4:\n\n");

    unsigned char** img = (unsigned char**)malloc(sizeof(unsigned char*)*3);
    for(i = 0; i < 3; i++){
        img[i] = (unsigned char*)malloc(sizeof(unsigned char)*3);
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            img[i][j] = '6';
        }
    }
    
   if(guardaImagem(img, 3, 3, "imagem1234.bin") == 0){
         printf("Erro ao salvar a imagem\n");
         return 0;
   }

    unsigned char** teste = carregaImagem(&lin, &col, "imagem1234.bin");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(teste[i][j] != '6'){
                x = 1;
                return 0;
            }
        }
    }

    if(x)
        printf("erro na questao 3,4\n");
    else
        printf("tudo certo na questao 3,4\n\nfoi utilizado a funcao guardaImagem para armazenar uma imagem com todos elementos igual a 6, e depois utilizei a funcao carregaImagem para carregar a imagem e verificar se todos os elementos eram iguais a 6\n");
      
    for(i = 0; i < 3; i++){
        free(img[i]);
    }

    free(img);
    
    printf("\n\n\nQuestao 5:\n\n");


    FILE *texto = fopen("texto12345.txt", "w");

    char buffer[256] = "textoparateste\ndever\nquantoscaracterestem\nagora";

    fprintf(texto, "%s", buffer);

    fclose(texto);

    int quant = quantcaracteres("texto12345.txt");

    if((unsigned int)quant != strlen(buffer)){
        printf("erro na questao 5\n");
        return 0;
    }
    else
        printf("tudo certo na questao 5\n\nfoi utilizado a funcao quantcaracteres para retornar quantos caracteres tinha no texto, e depois foi comparado o resultado com o retorno da funcao strlen\n");

    return 0;
}   