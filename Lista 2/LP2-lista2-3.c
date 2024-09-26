#include <stdio.h>
#define linha 10
#define coluna 10

void geraImgGreyB_R(unsigned char img[linha][coluna]);

int N = linha * coluna;     

int main(){
    unsigned char img[linha][coluna];
    int cont = 0;


    geraImgGreyB_R(img);
    

    for(int i = 0; i < linha; i++){                                         // Verifica se a imagem foi gerada corretamente
        for(int j = 0; j < coluna; j++){ 
            if(img[i][j] != 0){
                printf("Erro: img[%d][%d] = %hhu\n", i, j, img[i][j]);          // Se algum pixel não for igual a 0, a imagem não foi gerada corretamente
             
            }
            else cont++;                                        // Conta a quantidade de pixels gerados iguais a 0        
        }
    }

    if(linha * coluna == cont) printf("\n\nImagem gerada com sucesso!\n");     //linha * coluna representa a quantidade de pixels da imagem, que deve ser igual a cont
    else printf("\n\nErro na geracao da imagem!\n");

    return 0;
}

void geraImgGreyB_R(unsigned char img[linha][coluna]){
      if(N == 0){           //testa se N chegou a 0
        N = linha * coluna;     //reseta N para que a função possa ser chamada novamente
        return;             //encerra a função
    }
    N--;                    //decrementa N para controlar a quantidade de vezes que a função foi chamada
    img[0][0] = 0;          //atribui o valor 0 ao pixel atual
    geraImgGreyB_R(&img[0][1]);     //chama a função novamente, passando o endereço do próximo pixel
}