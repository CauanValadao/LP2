#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int den;
    double valor;
}frac;

int soma1(int x, int y);

frac soma(frac a, frac b);

int maxdiv(int a , int b);

int main(){

    frac a, b;
    
    printf("digite o numerador da primeira fracao: ");
    scanf("%d", &a.num);
    printf("digite o denominador da primeira fracao: ");
    scanf("%d", &a.den);
    printf("digite o numerador da segunda fracao: ");
    scanf("%d", &b.num);
    printf("digite o denominador da segunda fracao: ");
    scanf("%d", &b.den);

    frac resultado = soma(a, b);

    printf("A soma das fracoes e: %d/%d = %.2lf\n", resultado.num, resultado.den, resultado.valor);


    return 0;

}

int soma1(int x, int y){
    if(y == 0)
    return x;

    return soma1(++x, --y);
}

int maxdiv(int a, int b){
    if(b > a){
        int troca = a;
        a = b;
        b = troca;
    }

    int resto = a % b;

    while(resto){
        a = b;
        b = resto;
        resto = a % b;
    }

    return b;
}

frac soma(frac a, frac b){
    frac resultado;
    
    resultado.num = a.num * b.den + b.num * a.den;
    resultado.den = a.den * b.den;


    int mdc = maxdiv(resultado.num, resultado.den);

    if(mdc != 1){
        resultado.num /= mdc;
        resultado.den /= mdc;
    }

    resultado.valor = (double)resultado.num/resultado.den;

    return resultado;
}
