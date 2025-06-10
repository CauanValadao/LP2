#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define tamanho 20

void preencher(int *vetor, int N);

int buscar(int *vetor, int N, int x);

int main(){
    int vetor[tamanho] = {0};
    srand(time(NULL));

    preencher(vetor, tamanho);

    for(int i = 0; i < tamanho; i++){
        printf("%d\n",vetor[i]);
    }

    return 0;
}

void preencher(int *vetor, int N){
    int x;
    if(N == 0) return;
    while(1){
        x = rand()%(2*tamanho) + 1;
        if(buscar(vetor, tamanho, x)){
            vetor[N-1] = x;    
            preencher(vetor, N-1);
            return;
        }
    }
}

int buscar(int *vetor, int N, int x){
    if(N == 0) return 1;
    if(vetor[N-1] == x) return 0;
    return buscar(vetor, N-1, x);
}