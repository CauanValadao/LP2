/*Implemente uma função int quantMaiorZeros(float vet[ ], int n), 
que recebe um array de float de tamanho n, 
e retorna quantos elementos do array são maiores que zero. 
sem utilizar recursividade*/

int quantMaiorZeros(floar vet[], int n);

int quantMaiorZeros(floar vet[], int n){
    int soma = 0;
    for(int i = 0; i < n; i++){
        if(vet[i] > 0) soma++;
    }
    return soma;
}