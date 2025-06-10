/*Implemente uma função int quantMaiorZeros(float vet[ ], int n), 
que recebe um array de float de tamanho n, 
e retorna quantos elementos do array são maiores que zero. 
utilizando recursividade*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanho 10

int quantMaiorZerosRaux(float vet[ ], int n, int x);


int quantMaiorZerosR(float vet[ ], int n);

int main(){
    float vet[tamanho]; 
    int i, func, real = 0;
    srand(time(NULL));
    for(i = 0; i < tamanho; i++)
        vet[i] = rand()%10 - 5;
    
    func = quantMaiorZerosR(vet, tamanho);

    for(i = 0; i < tamanho; i++)
        if(vet[i] > 0) real++;

    if(real == func) printf("Deu certo");
    else printf("nao deu");
  
}

int quantMaiorZerosR(float vet[], int n){
    return quantMaiorZerosRaux(vet, n, 0);
}

int quantMaiorZerosRaux(float vet[ ], int n, int x){
    if(x == n) return 0;
    
    if(vet[x] > 0) return 1 + quantMaiorZerosRaux(vet, n, x + 1);

    else return quantMaiorZerosRaux(vet, n, x + 1);
}
