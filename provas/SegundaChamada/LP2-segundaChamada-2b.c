#include <stdio.h>

int inverteR(float vet[ ], int n){
    if(n == 0)
        return 0;
    if(!vet[n-1]){
        vet[n-1] = 1;
        return 1 + inverteR(vet, n-1);
    }
    else{
        vet[n-1] = 1/vet[n-1];
        return inverteR(vet, n-1);
    }
}

int main(){
    float vet[100];

    for(int i = 0; i < 100; i++){ //preenchendo todo o vetor igualmente
        vet[i] = 2;
    }

    vet[3] = 0;  // para testar quando algum elemento for 0

    int teste = inverteR(vet, 100);

    if(!teste || vet[3] != 1){ //teste se a funcao trabalhou corretamente com elementos iguais a 0
        printf("Codigo deu errado1");
        return 0;
    }
    teste = 0;

    vet[3] = 0.5;//retornando para o valor esperado para todos os elementos

    for(int i = 0; i < 100; i++){
        if(vet[i] != 0.5){
            teste = 1;
            break;
        }
    }

    if(teste)
        printf("Codigo deu errado");
    else
        printf("Codigo Substituiu os valores com sucesso");

    return 0;
}