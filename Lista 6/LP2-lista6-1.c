#include "cabecalhos6.h"
#include <string.h>


int saveImgGray(imgGray img, char* desc, char* fileName){
  int i;

  if(img.img == NULL || img._img == NULL){
    return 0;
  }

  char* nome = (char*)malloc(sizeof(char)*strlen(fileName) + 5);

  if(nome == NULL){
    printf("Erro ao alocar memoria\n");
    return 1;
  }

  strcpy(nome, fileName);
  strcat(nome, ".img");

  char* nome2 = (char*)malloc(sizeof(char)*strlen(fileName) + 5);

  if(nome2 == NULL){
    printf("Erro ao alocar memoria\n");
    free(nome);
    return 1;
  }

  strcpy(nome2, fileName);
  strcat(nome2, ".txt");
 /*--------------------------------------------------------------*/  

  FILE *imagem = fopen(nome, "wb");

  if(imagem == NULL){
    printf("Erro ao abrir o arquivo 1\n");
    return 1;
  }
  else{
    printf("Arquivo 1 aberto com sucesso\n");
  }


  fwrite(img._img, sizeof(uchar), img.nCol*img.nLin, imagem);

  fclose(imagem);

  /*--------------------------------------------------------------*/
  

  FILE *hed = fopen(nome2, "w");

  if(hed == NULL){
    printf("Erro ao abrir o arquivo 1 \n");
    return 1;
  }
  else{
    printf("Arquivo 2 aberto com sucesso\n");
  }

  i = fputs("gray\n", hed);

  if(i == EOF){
    printf("Erro ao escrever no arquivo\n");
    fclose(hed);
    return 1;
  }
  fprintf(hed, "%d\n%d\n%s\n%s", img.nLin, img.nCol, desc, nome);

  /*--------------------------------------------------------------*/

  fclose(hed);
  free(nome);
  free(nome2);
  return 1;  
}

int main(void){
  imgGray imagem;
  imagem.nLin = 10;
  imagem.nCol = 10;

  char desc[80] = "escrevendo so para mos";
  char fileName[20] = "lista06avx";

  imagem = alocaImagemGray(imagem.nLin, imagem.nCol);
  geraImgGrayW(imagem);
  printf("%d\n\n\n", imagem.img[0][0]);	

  int x = saveImgGray(imagem, desc, fileName);

  if(x == 1){
    printf("Arquivo salvo com sucesso\n");

  uchar img[imagem.nLin*imagem.nCol];

  FILE *arq = fopen("lista06avx.img", "rb");

  //fread(img, sizeof(img),1, arq);

  for(int i = 0; i < imagem.nLin*imagem.nCol; i++){
    fread(&img[i], sizeof(uchar), 1, arq);
  }

  for(int i = 0; i < imagem.nLin; i++){
    printf("\n");	
    for(int j = 0; j < imagem.nCol; j++){
      printf("%d ", img[i*imagem.nCol + j]);
    }
  }


  free(imagem._img);
  free(imagem.img);
  fclose(arq);
  return(0);
  }
}