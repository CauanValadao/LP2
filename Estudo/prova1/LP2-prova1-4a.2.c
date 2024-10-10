#include <stdlib.h>
#include <stdio.h>

int quantMaiorZerosR(float vet[ ], int n);
int quantMaiorZerosRaux(float vet[ ], int n, int i);

int quantMaiorZerosRaux(float vet[], int n, int i){
    if(i == n) return 0;
    
    if(vet[i] > 0) return 1 + quantMaiorZerosRaux(vet, n, i+1);

    else return quantMaiorZerosRaux(vet, n, i+1);
}

int quantMaiorZerosR(float vet[ ], int n){
    return quantMaiorZerosRaux(vet, n, 0);
}

int main(){
    int *vet;

    vet = (int*)malloc(sizeof(int)*10);

    for(int i = 0; i < 10; i++) vet[i] = 1;

    int quant = quantMaiorZerosR(vet, 10);

    if(quant == 10) printf("deu certo");
    else printf("deu errado");

    return 0;
}
