#include <stdlib.h>
#include <stdio.h>

void liberar(char *M, int m);

int main(){
    int **M; 
    int m;
    printf("Digite m: ");
    scanf("%d", &d);
    M = malloc (m * sizeof (int *));
    for (int i = 0; i < m; ++i)
    M[i] = malloc (n * sizeof (int));

    return 0;
}

void liberar(char *M, int m){
    int i;
    for(i = 0; i < m; i++)
        free(M[i]);
    free(M);
}