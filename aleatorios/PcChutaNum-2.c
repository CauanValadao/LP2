#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int x = rand()%100 + 1, chute = 50, pulo = 25;

    printf("eu (maquina) tenho que acertar o numero %d\n\n", x);

    printf("chute: %d \n\n", chute);

    for(int i = 0; i < 6; i++){
        if(chute > x) chute -= pulo;

        else if(chute < x) chute += pulo;

        printf("chute: %d \n\n", chute);

        pulo /= 2;

    }
    if(x != chute){
            if(chute > x) chute--;

        else chute ++;
        }

    printf("\n\nO numero e %d", chute);

    return 0;
}