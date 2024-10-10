/*Implemente uma função int quantCh(char str[], char ch) que 
recebe como parâmetro uma string C e um caractere,  
e retorna quantas vezes aparece o caractere ch na string str. */

int quantCh(char str[], char ch);

int quantCh(char str[], char ch){
    int i = 0, soma = 0;
    while(str[i] != '/0'){
        if(str[i] == ch) soma++;
        i++;
    }
    return soma;
}
