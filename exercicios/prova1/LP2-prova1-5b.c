/*Faça uma implementação da função int 
quantosParesR(int vet[ ], int n), que que retorna quantos 
elementos do array de inteiros, de tamanho n, são pares.
Faça a implementação sem utilizar recursividade; 
 */

int quantosPares(int vet[ ], int n);



int quantosPares(int vet[ ], int n){
    int soma = 0; i;

    for(i = 0; i < n; i++)
        if(vet[i]%2 == 0) soma++;

    return soma;
}