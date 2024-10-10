#include "cabecalhos.h"



int main(){
    int tam;
    unsigned char *vet;


    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    vet = geraArray1D(tam);

    free(vet);

    return 0;
}
