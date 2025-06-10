#include "cabecalhos6.h"
#include <string.h>

int loadHead(char* fileName, char* desc){
    char *nome = (char*)malloc(strlen(fileName) + 5);
    if(nome == NULL){
        printf("Erro ao alocar memoria");
        return 0;
    }

    strcpy(nome, fileName);
    strcat(nome, ".txt");

    FILE *hed = fopen(nome, "r");
    free(nome);

    
    if(hed == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    char tipo[6];
    if(fgets(tipo, 6, hed) == NULL){
        fclose(hed);
        printf("Erro ao ler o arquivo");
        return 0;
    }
    
    char buffer[256];
    fgets(buffer, sizeof(buffer), hed);
    fgets(buffer, sizeof(buffer), hed);

    if(fgets(desc, 80, hed) == NULL){
        fclose(hed);
        printf("Erro ao ler o arquivo");
        return 0;
    }

    fclose(hed);

    if(!strcmp(tipo, "gray\n"))
        return 1;

    else if(!strcmp(tipo, "RGB\n"))
        return 2;

    else 
        return 0;


}

int main(){

    char desc[80];

    int i = loadHead("lista06avx", desc);

    printf("i = %d", i);

    printf("\n%s", desc);

    return 0;
}
    