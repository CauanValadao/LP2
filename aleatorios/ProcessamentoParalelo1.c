#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NSIZE 1000

    int* alocavet(int linha, int coluna){
        return (int*)malloc(sizeof(int)*linha*coluna);
    }
    
    int** alocamat(int linha, int coluna, int* vet){
        int **mat;
        mat = (int**)malloc(sizeof(int*)*linha);
        for(int i = 0; i < linha; i++){
            mat[i] = &vet[i*coluna];
        }
        return mat;
    }

int main(){
    int *vet, linha = 10000, coluna = 10000, **mat, soma = 0, teste = 0, i, j;

    vet = alocavet(linha, coluna);

    for(i = 0; i < linha*coluna; i++){
        vet[i] = 1;
    }

    mat = alocamat(linha, coluna, vet);

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            if(mat[i][j] == 1) teste++;
        }
    }

    if(linha*coluna == teste) printf("Deu certo");
    else printf("Deu errado");



    free(vet);
    free(mat);





    return 0;
}