#define tamanho 20
//parte que vai para procimg.h

void drwLin(unsigned char img[tamanho][tamanho], int xA, int yA, int xB, int yB, unsigned char pixel);

/*  Função que desenha uma reta com base nas duas extremidades, (xA, yA) e (xB, yB).
    utiliza a cor armazenada em pixel.
*/

//parte que vai para procimg.c


//parte que vai para exemimg.c

#include <stdio.h>

int main(){
    unsigned char img[tamanho][tamanho], pixel = 178;
    int xA, xB, yA, yB, i, j;

    printf("intervalo de x: [0,639]\nintervalo de y: [0,479]\n\n");

    printf("Digite as coordenadas x e y de uma extremidade da reta:\n");
    scanf("%d%d", &xA, &yA);

    printf("\nDigite as coordenadas x e y da outra extremidade da reta:\n");
    scanf("%d%d", &xB, &yB);

    if(xA > 639 || xA < 0 || xB > 639 || xB < 0 || yA > 479 || yA < 0 || yB > 479 || yB < 0){
        printf("coordanada fora do intervalo");
        return 0;
    }
    for( i = 0; i < tamanho; i++){
        for( j = 0; j < tamanho; j++){
            img[i][j] = 176;
        }
    }

    

   
    drwLin(img, xA, yA, xB, yB, pixel);
    
    for( i = 0; i < tamanho; i++){
        printf("\n");
        for( j = 0; j < tamanho; j++){
            printf("%c", img[i][j]);
        }
    }



    return 0;
}
void drwLin(unsigned char img[tamanho][tamanho], int xA, int yA, int xB, int yB, unsigned char pixel){
    int inclinacao, x, y;

    inclinacao = (int) (yA - yB) / (xA - xB);

    if(xA > xB){
        x = xA;
        xA = xB;
        xB = x;
    }

    for(x = xA; x < xB; x++){
        y = inclinacao * x;
        img[x][y] = pixel;
    }
}
