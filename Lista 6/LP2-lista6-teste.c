#include <stdio.h>
#include <stdlib.h>

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


int saveImgGray(imgGray img, char* desc, char* fileName){
  int i;

  FILE *imagem = fopen(fileName, "wb");

  if(imagem == NULL){
    printf("Erro ao abrir o arquivo\n");
    return 1;
  }

  fwrite(img._img, sizeof(uchar), img.nCol*img.nLin, imagem);

  fclose(imagem);
  
  FILE *hed = fopen(fileName, "w");

  if(hed == NULL){
    printf("Erro ao abrir o arquivo\n");
    return 1;
  }

  i = fputs("gray\n", hed);

  if(i == EOF){
    printf("Erro ao escrever no arquivo\n");
    fclose(hed);
    return 1;
  }
  fprintf(hed, "%d\n%d\n%s\n%s", img.nLin, img.nCol, desc, fileName);

  fclose(hed);
  return 1;  
}

int main(void){
  
  imgGray imagem;
  imagem.nLin = 10;
  imagem.nCol = 10;

  char desc[80] = "arquivo de teste mas agora esse e ";
  char fileName[20] = "lista06teste.txt";

  int x = saveImgGray(imagem, desc, fileName);

  if(x == 1){
    printf("Arquivo salvo com sucesso\n");

  return(0);
  }
}