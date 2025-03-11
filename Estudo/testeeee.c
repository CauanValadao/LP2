#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int den;
    double valor;
}frac;

typedef struct{
    int linha;
    int coluna;
    int** mat;
    int* dados;
}matriz;

int soma1(int x, int y);

frac soma(frac a, frac b);

int maxdiv(int a , int b);

matriz alocamatriz(int l, int c);

void preenchematriz(matriz mat);

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


matriz alocamatriz(int l, int c){
    matriz erro;
    erro.linha = 0;
    erro.coluna = 0;
    erro.mat = NULL;
    erro.dados = NULL;

    if(l < 1 || c < 1) return erro;

    matriz mat;

    mat.linha = l;
    mat.coluna = c;
    
    mat.dados = (int*)malloc(sizeof(int)*l*c);

    if(mat.dados == NULL) return erro;

    mat.mat = (int**)malloc(sizeof(int*)*l);

    if(mat.mat == NULL){
        free(mat.dados);
        return erro;
    }

    for(int i = 0; i < l; i++)
        mat.mat[i] = &mat.dados[i*c];
    
    return mat;
}

void preenchematriz(matriz mat){
    for(int i = 0; i < mat.linha*mat.coluna; i++){
        printf("Digite o elemento [%d][%d] da matriz: \n", i/mat.coluna, i%mat.coluna);
        scanf("%d",mat.mat[i]);
    }
}

void imprimematriz(matriz mat){
    for(int i = 0; i < mat.linha; i++){
        printf("\n");
        for(int j = 0; j < mat.coluna; j++)
            printf("%d ", mat.mat[i][j]);
    }
}

int somaelementos(matriz mat){
    int some;
    for(int i = 0; i < mat.linha; i++){
        for(int j = 0; j < mat.coluna; j++)
         some += mat.mat[i][j];
    }
    return some;
}

void liberamemmat(matriz mat){
    if(mat.dados != NULL)
        free(mat.dados);
    if(mat.mat != NULL)
        free(mat.mat);
}
