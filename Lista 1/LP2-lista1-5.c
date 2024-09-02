//parte que vai para procimg.h
#define tamanho 30

void drwLin(unsigned char img[tamanho][tamanho], int xA, int yA, int xB, int yB, unsigned char pixel);

/*  Função que desenha uma reta com base nas duas extremidades, (xA, yA) e (xB, yB).
    utiliza a cor armazenada em pixel.
*/
#include <stdio.h>


void drwLin(unsigned char img[tamanho][tamanho], int xA, int yA, int xB, int yB, unsigned char pixel){
    if(xA > xB){
        int troca = xA;
        xA = xB;
        xB = troca;
        troca = yA;
        yA = yB;
        yB = troca;
    }
    img[yA][xA] = pixel;
    img[yB][xB] = pixel;

    int x = xA, y = yA, topo = xB, inteiro, teste = 1;
    float inclinacao,slope, decimal = 0, b;

    inclinacao = (float)(yA - yB)/(xA - xB);
    slope = inclinacao;


    
    while(x <= topo){
        inclinacao = slope;
        inclinacao += decimal;
        inteiro = inclinacao;
        decimal = inclinacao - inteiro;

       

        if(decimal > 0.5){
            inteiro++;
            decimal --;
        }
        else decimal = 0.5 - decimal;

        y += inteiro;

        img[y][x] = pixel;

        x++;



    }

   
}




int main(){
    unsigned char img[tamanho][tamanho], pixel = 178;
    int xA, xB, yA, yB;

    printf("intervalo de y: [0,639]\nintervalo de x: [0,479]\n\n");

    printf("Digite as coordenadas y e x de uma extremidade da reta:\n");
    scanf("%d%d", &yA, &xA);

    printf("\nDigite as coordenadas y e x da outra extremidade da reta:\n");
    scanf("%d%d", &yB, &xB);

    if(yA > 639 || yA < 0 || yB > 639 || yB < 0 || xA > 479 || xA < 0 || xB > 479 || xB < 0){
        printf("coordanada fora do intervalo");
        return 0;
    }
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            img[i][j] = 176;
        }
    }

    drwLin(img, xA, yA, xB, yB, pixel);

    for(int i = 0; i < tamanho; i++){
        printf("\n");
        for(int j = 0; j < tamanho; j++){
            printf("%c", img[i][j]);
        }
    }



    return 0;
}

