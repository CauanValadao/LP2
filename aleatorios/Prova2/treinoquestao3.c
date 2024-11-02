#include <stdlib.h>
#include <time.h>
#include <stdio.h>

char alfabeto[26] = {'a','e','i','o','u','b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};

char* geraPalavra(int tam){
    tam = rand()%tam + 2;
    char* palavra = (char*)malloc(sizeof(char)*tam + 1);
    int vez = rand()%2, i;

    for(i = 0; i < tam; i++){
        if(vez){
            palavra[i] = alfabeto[rand()%5];
            vez = 0;
        }
        else{
            palavra[i] = alfabeto[rand()%21 + 5];
            vez++;
        }
    }
    palavra[i] = '\0';
    return palavra;
}

int main(){
    srand(time(NULL));
    char* palavra = geraPalavra(100);
    printf("%s", palavra);

    free(palavra);
    return 0;
}
