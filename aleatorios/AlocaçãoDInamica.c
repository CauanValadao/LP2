#include <stdlib.h>
#include <stdio.h>

char* transtring(char c);

int main(){
    char* c;
    char *x;
    printf("Digite c:");
    scanf("%c", &c);

    x = transtring(c);

    printf("\n%s", x);

    free(x);

    
}

char* transtring(char c){
    char *s;
    s = malloc(sizeof(char)*2);
    s[0] = c;
    s[1] = '\0';
    return s;
}