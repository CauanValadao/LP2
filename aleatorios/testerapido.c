#include <stdio.h>

int main(){
    int n;
    printf("Digite o valor de N: ");
    scanf("%d", &n);

    int resultado = (n*n + n) / 2;

    printf("Resultado da soma iterativa dos termos: %d", resultado);
    return 0;
}
