#include <stdlib.h>


unsigned char* geraArray1D(int tam);

int main(){
    int tam;
    unsigned char *vet;


    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    vet = geraArray1D(tam);

    free(vet);

    return 0;
}

unsigned char* geraArray1D(int tam){
    return (unsigned char*)malloc(sizeof(unsigned char) * tam);
}   