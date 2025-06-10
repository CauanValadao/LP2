/*Faça uma implementação da função int 
quantosParesR(int vet[ ], int n), que que retorna quantos 
elementos do array de inteiros, de tamanho n, são pares.
Faça a implementação utilizando recursividade; 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamanho 10

int x = -1;

int quantosParesR(int vet[ ], int n);

int main(){
    int i, func, real = 0, vet[tamanho];
    srand(time(NULL));
    for(i = 0; i < tamanho; i++)
        vet[i] = rand()%10 - 5;
    
    func = quantosParesR(vet, tamanho);

    for(i = 0; i < tamanho; i++)
        if(vet[i]%2 == 0) real++;

    if(real == func) printf("Deu certo");
    else printf("nao deu");
  
}

int quantosParesR(int vet[ ], int n){
    x++;

    if (x == n){
        x = 0;
        return 0;
    }

    if(vet[x] % 2 == 0) return 1 + quantosParesR(vet, n);

    else return quantosParesR(vet, n);
}