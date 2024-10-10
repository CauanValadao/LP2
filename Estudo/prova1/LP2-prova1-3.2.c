#include <stdio.h>

int cont = -1;

int quantCh(char str[], char ch){
    cont++;
    if(str[cont] == '\0'){
        cont = -1;
        return 0;
    }

    if(str[cont] == ch) return 1 + quantCh(str, ch);

    else return quantCh(str, ch);
}

int main(){
    char vet[10];

    vet[9] = '\0';

    for(int i = 0; i < 9; i++) vet[i] = 1;

    vet[0] = 2;

    int quant = quantCh(vet, 1);

    printf("%d", quant);

    return 0;
}