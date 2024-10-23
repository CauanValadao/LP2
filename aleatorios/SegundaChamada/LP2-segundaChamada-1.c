#include <stdio.h>
#include <string.h>

int troca(char str[], char ch1, char ch2){
    int i = 0, trocou = 0;
    while(str[i]){
        if(str[i] == ch1){
            str[i] = ch2;
            trocou = 1;
        }
        i++;
    }
    return trocou;
}

int main(){
    char str[100], strcopia[100], ch1, ch2, teste = 0;
    printf("Digite uma string: ");
    gets(str);

    strcpy(strcopia, str);

    printf("Digite o caractere a ser substituido: ");
    scanf("%c", &ch1);
    printf("Digite o caractere que substituira: ");
    scanf(" %c", &ch2);
    
    troca(str, ch1, ch2);

    for(int i = 0; str[i]; i++){
        if(strcopia[i] == ch1 && str[i] != ch2){
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