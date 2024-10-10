    #include <stdlib.h>
    #include <stdio.h>

    unsigned char** geraArray2D(int nLin, int nCol);

int main(){
    int linha, coluna;
    unsigned char **mat;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &linha);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &coluna);

    mat = geraArray2D(linha, coluna);

    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            mat[i][j] = 1;
        }
    }

    for(int i = 0; i < linha; i++){
        printf("\n");
        for(int j = 0; j < coluna; j++){
            printf("%d ", mat[i][j]);
        }
    }

    for(int i = 0; i < linha; i++){
        free(mat[i]);
    }
    free(mat);
    

    

    return 0;
}

unsigned char** geraArray2D(int nLin, int nCol){
    unsigned char **mat;
    mat = (unsigned char**)malloc(sizeof(unsigned char*)*nLin);
    for(int i = 0; i < nLin; i++){
        mat[i] = (unsigned char*)malloc(sizeof(unsigned char)*nCol);
    }
    return mat;
}

