#include "procimg.h"

int main(){
    int x, i, j, int pixel;
    

    unsigned char* vet;

    unsigned char** img = alocaImagem2D(&vet, 10, 10);

    printf("Escolha qual funcao deseja rodar");
    scanf("%d", &x);

    while(x){
        switch (x)
        {
        case 1:
            printf("Matriz ja criada");
            break;
        case 2:
            printf("Matriz ja criada");
            break;
        case 3:
            printf("Digite o valor de pixel");
            scanf("%d", &pixel);
            geraImgGreyFull_D1(vet, 10, 10, pixel);
        
        default:
            break;
        }
    }
    

    free(vet);
    free(img);

    return 0;
}