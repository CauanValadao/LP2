

int inverte(float vet[ ], int n){
    int zero = 0;
    while(n){
        if(!vet[n-1]){
            vet[n-1] = 1;
            zero = 1;
        }
        else{
            vet[n-1] = 1/vet[n-1];
        }
        n--;
    }
    return zero;
}

int main(){
    float vet[100];

    for(int i = 0; i < 100; i++){
        vet[i] = 2;
    }

    int teste = inverte(vet, 100);

    for(int i = 0; i < 100; i++){
        if(vet[i] != 0.5){
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