#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef void (*Metodo)(void* jogo);
typedef void(*MetodoInt)(void* jogo, long unsigned int semente);



typedef struct{
    int* jogo;
    int vezes;
    int min;
    int tam;
    long unsigned int semente;
    

    Metodo jogaOsDados;
    Metodo printJogos;
    MetodoInt mudaSemente;
}tJogo;

void printJogo(void* jogo);
void jogaOsDados(void* jogo);
void mudaSemente(void* jogo, long unsigned int semente);
tJogo inicializaJogo(int vezes, int min, int tam, long unsigned int semente);


int main(){

    int vezes, min, tam;
    long unsigned int semente;

    printf("Digite a quant de sorteios: ");
    scanf("%d", &vezes);
    printf("Digite o valor min: ");
    scanf("%d", &min);
    printf("Digite o intervalo: ");
    scanf("%d", &tam);
    printf("Digite a semente: ");
    scanf("%ld", &semente);

    tJogo jogo = inicializaJogo(vezes, min, tam, semente);

    jogaOsDados(&jogo);

    printJogo(&jogo);

    free(jogo.jogo);
    


    return 0;
}

tJogo inicializaJogo(int vezes, int min, int tam, long unsigned int semente){
    tJogo jogo;
    jogo.jogo = (int*)malloc(sizeof(int)*vezes);
    jogo.vezes = vezes;
    jogo.min = min;
    jogo.tam = tam;
    jogo.semente = semente;
    jogo.jogaOsDados = jogaOsDados;
    jogo.printJogos = printJogo;
    jogo.mudaSemente = mudaSemente;

    return jogo;
}

void jogaOsDados(void* jogo){
    tJogo *jogo_ = (tJogo*)jogo;
    srand(jogo_->semente);

    for(int i = 0; i < jogo_->vezes; i++)
        jogo_->jogo[i] = jogo_->min + rand()%jogo_->tam;

}

void mudaSemente(void* jogo, long unsigned int semente){
    tJogo *jogo_ = (tJogo*)jogo;
    jogo_->semente = semente;
    free(jogo_->jogo);
    jogo_->jogo = (int*)malloc(sizeof(int)*jogo_->vezes);
}

void printJogo(void* jogo){
    tJogo *jogo_ = (tJogo*)jogo;
    for(int i = 0; i < jogo_->vezes; i++)
        printf("valor %d = %d\n", i + 1, jogo_->jogo[i]);
}