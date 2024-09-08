

#include <stdio.h>
#define linha 20
#define coluna 20

void geraImgGreyW_R(unsigned char *img,int N);

int main(){
    unsigned char img[linha][coluna];
    int cont = 0;


    geraImgGreyW_R(img, linha*coluna);
    

    for(int i = 0; i < linha; i++){                                         // Verifica se a imagem foi gerada corretamente
        for(int j = 0; j < coluna; j++){ 
            if(img[i][j] != 255){
                printf("Erro: img[%d][%d] = %hhu\n", i, j, img[i][j]);          // Se algum pixel não for igual a 0, a imagem não foi gerada corretamente
             
            }
            else cont++;                                        // Conta a quantidade de pixels gerados iguais a 0        
        }
    }

    if(linha * coluna == cont) printf("\n\nImagem gerada com sucesso!\n");     //linha * coluna representa a quantidade de pixels da imagem, que deve ser igual a cont
    else printf("\n\nErro na geracao da imagem!\n");

    return 0;
}

void geraImgGreyW_R(unsigned char *img,int N){
    if(N == 0) return;    
    *img= 255;          
    geraImgGreyW_R(img+1, N-1);
}