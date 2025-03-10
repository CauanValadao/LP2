/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

typedef struct{
    uchar R, G, B;
}tRGB;

typedef struct{
    uchar *_img;
    uchar **img;
    int nLin, nCol;
}imgGray;

typedef struct{
    tRGB *_img;
    tRGB **img;
    int nLin, nCol;
}imgRGB;

struct imagens{
    imgGray img;
    struct imagens *prox;
};

typedef struct imagens tImagens;
*/


int saveImgGray(imgGray img, char* desc, char* fileName){
  int i;

  if(img.img == NULL || img._img == NULL){
    return 0;
  }

  char* nome = (char*)malloc(sizeof(char)*strlen(fileName) + 5);

  if(nome == NULL)
    return 0;
  

  strcpy(nome, fileName);
  strcat(nome, ".img");

  char* nome2 = (char*)malloc(sizeof(char)*strlen(fileName) + 5);

  if(nome2 == NULL){
    free(nome);
    return 0;
  }

  strcpy(nome2, fileName);
  strcat(nome2, ".txt");
 /*--------------------------------------------------------------*/  

  FILE *imagem = fopen(nome, "wb");

  if(imagem == NULL)
    return 0;

  fwrite(img._img, sizeof(uchar), img.nCol*img.nLin, imagem);

  fclose(imagem);

  /*--------------------------------------------------------------*/
  

  FILE *hed = fopen(nome2, "w");

  if(hed == NULL)
    return 0;
 
  i = fputs("gray\n", hed);

  if(i == EOF){
    fclose(hed);
    return 0;
  }
  fprintf(hed, "%d\n%d\n%s\n%s", img.nLin, img.nCol, desc, nome);

  /*--------------------------------------------------------------*/

  fclose(hed);
  free(nome);
  free(nome2);
  return 1;  
}

int saveImgRGB(imgRGB img, char* desc, char* fileName){
    if(img.img == NULL || img._img == NULL){
        return 0;
    }

    char* nome = (char*)malloc(sizeof(char)*strlen(fileName) + 5);
    
    if(nome ==  NULL)
        return 0;
    
    strcpy(nome, fileName);
    strcat(nome, ".img");

    char* nome2 = (char*)malloc(sizeof(char)*strlen(fileName) + 5);

    if(nome2 == NULL){
        free(nome);
        return 0;
    }
    strcpy(nome2, fileName);
    strcat(nome2, ".txt");
    
    /*--------------------------------------------------------------*/

    FILE *imagem = fopen(nome, "wb");
    
    if(imagem == NULL){
        return 0;
        free(nome);
        free(nome2);
    }

    fwrite(img._img, sizeof(tRGB), img.nCol*img.nLin, imagem);

    fclose(imagem);
    
    /*--------------------------------------------------------------*/

    FILE *hed = fopen(nome2, "w");

    if(hed == NULL){
        return 0;
        free(nome);
        free(nome2);
    }
    int i = fputs("RGB\n", hed);

    if(i == EOF){
    fclose(hed);
    return 0;
    }

    fprintf(hed, "%d\n%d\n%s\n%s\n", img.nLin, img.nCol, desc, nome);

    fclose(hed);
    free(nome);
    free(nome2);

    return 1;
}

int loadHead(char* fileName, char* desc){
    char *nome = (char*)malloc(strlen(fileName) + 5);
    if(nome == NULL)
        return 0;
    
    strcpy(nome, fileName);
    strcat(nome, ".txt");

    FILE *hed = fopen(nome, "r");
    free(nome);

    if(hed == NULL)
        return 0;

    char tipo[6];
    if(fgets(tipo, 6, hed) == NULL){
        fclose(hed);
        return 0;
    }
    
    char buffer[256];
    fgets(buffer, sizeof(buffer), hed);
    fgets(buffer, sizeof(buffer), hed);

    if(fgets(desc, 80, hed) == NULL){
        fclose(hed);
        return 0;
    }
    desc[strcspn(desc, "\n")] = '\0';

    fclose(hed);

    if(!strcmp(tipo, "gray\n"))
        return 1;

    else if(!strcmp(tipo, "RGB\n"))
        return 2;

    else 
        return 0;
}

imgGray loadImgGray(char* fileName){
/*------------------abrindo arquivo hed--------------------------------*/
    imgGray img;
    img.img = NULL;
    img._img = NULL;
    
    char *nome = (char*)malloc(strlen(fileName) + 5);
    if(nome == NULL)
        return img;
    
    strcpy(nome, fileName);
    strcat(nome, ".txt");

    FILE *hed = fopen(nome, "r");
    free(nome);
    if(hed == NULL)
        return img;
    
    char buffer[256];
    fgets(buffer, sizeof(buffer), hed);

/*------------------lendo linha e coluna--------------------------------*/
    /*
    if (fgets(buffer, sizeof(buffer), hed) == NULL) {
        fclose(hed);
        return img;
    }
    img.nLin = atoi(buffer);

    if (fgets(buffer, sizeof(buffer), hed) == NULL) {
        fclose(hed);
        return img;
    }
    img.nCol = atoi(buffer);
    */
    int i = 0;
    char x, numero[10];
    x = fgetc(hed);
    do{
        numero[i] = x;
        i++;
        x = fgetc(hed);
    }while(x != '\n');
    numero[i] = '\0';

    img.nLin = atoi(numero);

    i = 0;
    x = fgetc(hed);
    do{
        numero[i] = x;
        i++;
        x = fgetc(hed);
    }while(x != '\n');
    numero[i] = '\0';

    img.nCol = atoi(numero);

    fclose(hed);
/*-------------------------copiando imagem-----------------------------------------*/
    char *nome2 = (char*)malloc(strlen(fileName) + 5);
    if(nome2 == NULL)
        return img;
    
    strcpy(nome2, fileName);
    strcat(nome2, ".img");

    FILE *imagem = fopen(nome2, "rb");
    free(nome2);
    if(imagem == NULL)
        return img;
    
    img = alocaImagemGray(img.nLin, img.nCol);

    if(img.img == NULL || img._img == NULL){
        fclose(imagem);
        return img;
    }

    fread(img._img, sizeof(uchar), img.nLin*img.nCol, imagem);

    fclose(imagem);
    return img;
}

imgRGB loadImgRGB(char* fileName){
    imgRGB img;
    img._img = NULL;
    img.img = NULL;

    char *nome = (char*)malloc(strlen(fileName) + 5);
    if(nome == NULL)
        return img;
    
    strcpy(nome, fileName);
    strcat(nome, ".txt");

    FILE *hed = fopen(nome, "r");
    free(nome);
    if(hed == NULL)
        return img;
    
    char buffer[256];
    fgets(buffer, sizeof(buffer), hed);

/*------------------lendo linha e coluna--------------------------------*/
    if (fgets(buffer, sizeof(buffer), hed) == NULL) {
        fclose(hed);
        return img;
    }
    img.nLin = atoi(buffer);

    if (fgets(buffer, sizeof(buffer), hed) == NULL) {
        fclose(hed);
        return img;
    }
    img.nCol = atoi(buffer);

    fclose(hed);
/*-------------------------copiando imagem-----------------------------------------*/
    char *nome2 = (char*)malloc(strlen(fileName) + 5);
    if(nome2 == NULL)
        return img;
    
    strcpy(nome2, fileName);
    strcat(nome2, ".img");

    FILE *imagem = fopen(nome2, "rb");
    free(nome2);
    if(imagem == NULL)
        return img;

    img = alocaImagemRGB(img.nLin, img.nCol);
    
    if(img.img == NULL || img._img == NULL){
        fclose(imagem);
        return img;
    }

    fread(img._img, sizeof(tRGB), img.nLin*img.nCol, imagem);

    fclose(imagem);
    return img;
}

int saveImgGrayBin(imgGray img, char* fileName){
    if(img.img == NULL || img._img == NULL)
        return 0;

    char *nome = (char*)malloc(strlen(fileName) + 5);
    if(nome == NULL)
        return 0;
    strcpy(nome, fileName);
    strcat(nome, ".bin");

    FILE *imagem = fopen(nome, "wb");
    free(nome);
    if(imagem == NULL)
        return 0;

    fwrite("bin\n", sizeof(char), strlen("bin\n"), imagem);
    fwrite(&img.nLin, sizeof(img.nLin), 1, imagem);
    fwrite(&img.nCol, sizeof(img.nCol), 1, imagem);
    fwrite(img._img, sizeof(uchar), img.nCol*img.nLin, imagem);

    fclose(imagem);
    return 1;
}

int saveImgRGBBin(imgRGB img, char* fileName){
    if(img.img == NULL || img._img == NULL)
        return 0;

    char *nome = (char*)malloc(strlen(fileName) + 5);
    if(nome == NULL)
        return 0;
    strcpy(nome, fileName);
    strcat(nome, ".bin");

    FILE *imagem = fopen(nome, "wb");
    free(nome);
    if(imagem == NULL)
        return 0;

    if(fwrite("bin\n", sizeof(char), strlen("bin\n"), imagem) != strlen("bin\n")){
        fclose(imagem);
        return 0;
    }
    if(fwrite(&img.nLin, sizeof(int), 1, imagem) != 1){
        fclose(imagem);
        return 0;
    }
    if(fwrite(&img.nCol, sizeof(int), 1, imagem) != 1){
        fclose(imagem);
        return 0;
    }
    if(fwrite(img._img, sizeof(tRGB), img.nLin*img.nCol, imagem) != (size_t)(img.nLin*img.nCol)){
        fclose(imagem);
        return 0;
    }
       
    fclose(imagem);
    return 1;
}

imgGray loadImgGrayBin(char* fileName){
    imgGray img;
    img.img = NULL;
    img._img = NULL;

    char *nome = (char*)malloc(strlen(fileName) + 5);
    if(nome == NULL)
        return img;
    strcpy(nome, fileName);
    strcat(nome, ".bin");

    FILE *imagem = fopen(nome, "rb");
    free(nome);
    if(imagem == NULL)
        return img;
    
    if(fseek(imagem, strlen("bin\n"), SEEK_SET)){
        fclose(imagem);
        return img;
    }

    if(fread(&img.nLin, sizeof(int), 1, imagem) != 1){
        fclose(imagem);
        return img;
    }
    if(fread(&img.nCol, sizeof(int), 1, imagem) != 1){
        fclose(imagem);
        return img;
    }
   
    img = alocaImagemGray(img.nLin, img.nCol);

    if(fread(img._img, sizeof(uchar), img.nLin*img.nCol, imagem) != (size_t)(img.nLin*img.nCol)){
        free(img._img);
        free(img.img);
        img._img = NULL;
        img.img = NULL;
    }

    fclose(imagem);
    return img;
}

imgRGB loadImgRGBBin(char* fileName){
    imgRGB img;
    img._img = NULL;
    img.img = NULL;

    char *nome = (char*)malloc(strlen(fileName) + 5);
    if(nome == NULL)
        return img;
    strcpy(nome, fileName);
    strcat(nome, ".bin");

    FILE *imagem = fopen(nome, "rb");
    free(nome);
    if(imagem == NULL)
        return img;
    
    if(fseek(imagem, strlen("bin\n"), SEEK_SET)){
        fclose(imagem);
        return img;
    }

    if(fread(&img.nLin, sizeof(int), 1, imagem) != 1){
        fclose(imagem);
        return img;
    }
    if(fread(&img.nCol, sizeof(int), 1, imagem) != 1){
        fclose(imagem);
        return img;
    }
    img = alocaImagemRGB(img.nLin, img.nCol); 

    if(fread(img._img, sizeof(tRGB), img.nLin*img.nCol, imagem) != (size_t)(img.nLin*img.nCol)){
        free(img._img);
        free(img.img);
        img._img = NULL;
        img.img = NULL;
    }

    fclose(imagem);
    return img;
}

/*-------------------------------------------------------------------------------------*/

imgGray alocaImagemGray(int nLin, int nCol){
    imgGray imagem;
    
    imagem.nLin = nLin;
    imagem.nCol = nCol;
    
    imagem._img = (uchar*)malloc(sizeof(uchar)*nLin*nCol);
    if(imagem._img == NULL){
        imagem.img = NULL;
        return imagem;
    }

    imagem.img = (uchar**)malloc(sizeof(uchar*)*nLin);
    if(imagem.img == NULL){
        free(imagem._img);
        imagem._img = NULL;
        return imagem;
    }

    for(int i = 0; i < nLin; i++){
        imagem.img[i] = &imagem._img[i*nCol];
    }

    return imagem;
}

imgRGB alocaImagemRGB(int nLin, int nCol){
    imgRGB imagem;
    imagem.nLin = nLin;
    imagem.nCol = nCol;

    imagem._img = (tRGB*)malloc(sizeof(tRGB)*nLin*nCol);
    if(imagem._img == NULL){
        imagem.img = NULL;
        return imagem;
    }

    imagem.img = (tRGB**)malloc(sizeof(tRGB*)*nLin);
    if(imagem.img == NULL){
        free(imagem._img);
        imagem._img = NULL;
        return imagem;
    }

    for(int i = 0; i < nLin; i++){
        imagem.img[i] = &imagem._img[i*nCol];
    }

    return imagem;
}

int geraImgGrayFull(imgGray img, uchar pixel){
    if(img.img == NULL || img._img == NULL) return 0;

    for(int i = 0; i < img.nCol*img.nLin; i++) img._img[i] = pixel;

    return 1;
}

int geraImgRGBFull(imgRGB img, tRGB pixel){
    if(img.img == NULL || img._img == NULL) return 0;

    for(int i = 0; i < img.nCol*img.nLin; i++){
        img._img[i].R = pixel.R;
        img._img[i].G = pixel.G;
        img._img[i].B = pixel.B;
    }

    return 1;
}

int geraImgGrayB(imgGray img){
    return geraImgGrayFull(img, 0);
}

int geraImgRGBB(imgRGB img){
    tRGB pixel;
    pixel.R = 0;
    pixel.G = 0;
    pixel.B = 0;
    return geraImgRGBFull(img, pixel);
}

int geraImgGrayW(imgGray img){
    return geraImgGrayFull(img, 255);
}

int geraImgRGBW(imgRGB img){
    tRGB pixel;
    pixel.R = 255;
    pixel.G = 255;
    pixel.B = 255;
    return geraImgRGBFull(img, pixel);
}

unsigned char geraPixelGrey(int tipo){

    int prob, valor;

    prob = rand() % 100;

    if(tipo < 0){
        if(prob < 80) valor = rand() % 128;
        
        else valor = rand() % 256;
    }
    else if(tipo > 0){
        if(prob < 80) valor = rand() % 128 + 128;

        else valor = rand() % 256;
    }
    else valor = rand() % 256;

    return (unsigned char) valor;
}

int geraImgGray(imgGray img, int tipo){
    if(img.img == NULL || img._img == NULL) return 0;

    for(int i = 0; i < img.nCol * img.nLin; i++){
        img._img[i] = geraPixelGrey(tipo);
    }
    return 1;
}

int geraImgRGB(imgRGB img, int tipo){
    if(img.img == NULL || img._img == NULL) return 0;

    for(int i = 0; i < img.nCol * img.nLin; i++){
        img._img[i].R = geraPixelGrey(tipo);
        img._img[i].G = geraPixelGrey(tipo);
        img._img[i].B = geraPixelGrey(tipo);
    }

    return 1;
}

int pixelGrayMax(imgGray img){
    if(img.img == NULL || img._img == NULL) return 256;

    int maior = img._img[0];

    for(int i = 0; i < img.nCol * img.nLin; i++){
        if(img._img[i] > maior) maior = img._img[i];
    }

    return maior;
}

int pixelGrayMin(imgGray img){
    if(img.img == NULL || img._img == NULL) return -1;

    int menor = img._img[0];

    for(int i = 0; i < img.nCol * img.nLin; i++){
        if(img._img[i] < menor) menor = img._img[i];
    }

    return menor;
}

tRGB pixelRGBMax(imgRGB img){
    if(img.img == NULL || img._img == NULL){
        tRGB erro;
        erro.R = -1;
        erro.G = -1;
        erro.B = -1;
        return erro;
    }

    tRGB maior;
    maior.R = img._img[0].R;
    maior.G = img._img[0].G;
    maior.B = img._img[0].B;

    for(int i = 0; i < img.nCol * img.nLin; i++){
        if(img._img[i].R > maior.R) maior.R = img._img[i].R;
        if(img._img[i].G > maior.G) maior.G = img._img[i].G;
        if(img._img[i].B > maior.B) maior.B = img._img[i].B;
    }

    return maior;
}

tRGB pixelRGBMin(imgRGB img){
    if(img.img == NULL || img._img == NULL){
        tRGB erro;
        erro.R = -1;
        erro.G = -1;
        erro.B = -1;
        return erro;
    }

    tRGB menor;
    menor.R = img._img[0].R;
    menor.G = img._img[0].G;
    menor.B = img._img[0].B;

    for(int i = 0; i < img.nCol * img.nLin; i++){
        if(img._img[i].R < menor.R) menor.R = img._img[i].R;
        if(img._img[i].G < menor.G) menor.G = img._img[i].G;
        if(img._img[i].B < menor.B) menor.B = img._img[i].B;
    }

    return menor;
}

int* somaPorLinhasGray(imgGray img){
    int *vet = (int*)calloc(sizeof(int),img.nLin);

    for(int i = 0; i < img.nLin; i++){
        for(int j = 0; j < img.nCol; j++)
            vet[i] += img.img[i][j];
    }
    return vet;
}

int* somaPorColunasGray(imgGray img){
    int *vet = (int*)calloc(sizeof(int), img.nCol);

    for(int j = 0; j < img.nCol; j++){
        for(int i = 0; i < img.nLin; i++)
            vet[j] += img.img[i][j];
    }
    return vet;
}

imgGray imagemcinza(imgRGB img){
    imgGray imgcinza;

    if(img.img == NULL || img._img == NULL){
        imgcinza.img = NULL;
        imgcinza._img = NULL;
        return imgcinza;
    }

    imgcinza = alocaImagemGray(img.nLin, img.nCol);

    if(imgcinza.img == NULL || imgcinza._img == NULL)
        return imgcinza;
    
    for(int i = 0; i < img.nLin * img.nCol; i++)
        imgcinza._img[i] = ((uchar)(0.3 * img._img[i].R + 0.59 * img._img[i].G + 0.11 * img._img[i].B));

    return imgcinza;

}
