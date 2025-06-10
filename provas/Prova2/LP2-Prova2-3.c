#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct{
    int num;
    int den;
    double valor;
}frac;

frac* geraRandomArray(int tam);

int main(){
    srand(time(NULL));
    int tam, i;
    frac *vet;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    vet = geraRandomArray(tam);

    for(i = 0; i < tam; i++){
        printf("Elemento %d:\nnum = %d\nden = %d\nvalor = %lf\n\n", i, vet[i].num, vet[i].den, vet[i].valor);
    }
    

    
    free(vet);
    return 0;

}

frac* geraRandomArray(int tam){
    frac* vet = (frac*)malloc(sizeof(frac)*tam);
    if(vet == NULL)
        return vet;
    
    for(int i = 0; i < tam; i++){
        vet[i].num = rand()%201 - 100;
        vet[i].den = rand()%201 - 100;
        if(!vet[i].den)
            vet[i].valor = 1000000;
        else
            vet[i].valor = 1.0*vet[i].num/vet[i].den;
    }
    return vet;
}