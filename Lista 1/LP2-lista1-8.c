#include <stdio.h>
#define linha 100
#define coluna 100

void drwTriang(unsigned char img[linha][coluna], int xA, int yA, int xB, int yB, int xC, int yC, unsigned char pixel);

int main(){
    int xA, yA, xB, yB, xC, yC, i, j;
    unsigned char img[linha][coluna], pixel;

    printf("Digite as coordenadas do ponto A:\n");
    scanf("%d%d", &xA, &yA);
    printf("Digite as coordenadas do ponto B:\n");
    scanf("%d%d", &xB, &yB);
    printf("Digite as coordenadas do ponto C:\n");
    scanf("%d%d", &xC, &yC);

    printf("\nDigite a cor desejada (valor entre 0 e 255): ");
    scanf("%hhu", &pixel);
    


    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            img[i][j] = 176;
        }
    }

    drwTriang(img, xA, yA, xB, yB, xC, yC, pixel);

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf("%c", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void drwTriang(unsigned char img[linha][coluna], int xA, int yA, int xB, int yB, int xC, int yC, unsigned char pixel){
    int xm = xA, xf = xB, xi = xC, ym = yA, yf = yB, yi = yC, i, j, caso;
    float mi, mm, mf, bi, bm, bf;

    //Testa se os pontos estão dentro da matriz
    if(xA > coluna || xB > coluna || xC > coluna || yA > linha || yB > linha || yC > linha) return;
    
    if(xA == xB && xB == xC) return;

    if(yA == yB && yB == yC) return;

    //Ordena os pontos em termos de x
    if(xi > xf){
        i = xi;
        xi = xf;
        xf = i;
        i = yi;
        yi = yf;
        yf = i;
    }
    if(xi > xm){
        i = xi;
        xi = xm;
        xm = i;
        i = yi;
        yi = ym;
        ym = i;
    }
    if(xm > xf){
        i = xm;
        xm = xf;
        xf = i;
        i = ym;
        ym = yf;
        yf = i;
    }
    //printf("\nxm = %d, ym = %d, xf = %d, yf = %d, xi = %d, yi = %d\n\n\n", xm, ym, xf, yf, xi, yi);

    //determina as extremidades de Y
    if(yC > yA){
        i = yC;
        yC = yA;
        yA = i;
    }
    if(yC > yB){
        i = yC;
        yC = yB;
        yB = i;
    }
    if(yB > yA){
        i = yB;
        yB = yA;
        yA = i;
    }
    //printf("yA = %d, yB = %d, yC = %d\n", yA, yB, yC);
    
    //Define o caso
    if(yi > ym) caso = 1;
    else caso = 2;

    i = 0;
    j = 0;

    //Calcula as retas e detecta se são verticais. Se forem, calcula apenas o necessário.
    if(xi != xm){
    mi = (float)(yi - ym)/(xi - xm);
    bi = yi - mi*xi;
     }
     else{
        i = 1;
        caso = 0;
     } 
    
    if(xf != xm){
    mf = (float)(yf - ym)/(xf - xm);
    bf = yf - mf*xf;
    }
    else {
        i = 2;
        mf = mi;
        bf = bi;
        caso = 0;
    }

    mm = (float)(yi - yf)/(xi - xf);
    bm = yi - mm*xi;

    //faz a troca de valores para que as retas sejam desenhadas corretamente no caso 0.
    if((i == 1 && ym > yi) || (i == 2 && ym > yf)){
        j = bm;
        bm = bf;
        bf = j;
        j = mm;
        mm = mf;
        mf = j;
    }

    //printf("\nmi = %f, bi = %f, mf = %f, bf = %f, mm = %f, bm = %f\n", mi, bi, mf, bf, mm, bm);

    //Desenha o triangulo

    //printf("\ncaso = %d\n",caso);

    switch (caso){

        case 0:
            for(i = yC; i <= yA; i++){
                for(j = xi; j <= xf; j++){
                    if(i <= (bm + mm*j) && i >= (bf + mf*j)) 
                        img[i][j] = pixel;
                }
            }
            break;
        case 1:
            for(i = yC; i <= yA; i++){
                for(j = xi; j <= xm; j++){
                    if(i >= (bi + mi*j) && i <= (bm + mm*j)) 
                        img[i][j] = pixel; 
                }
            }
            for(i = yC; i <= yA; i++){
                for(j = xm; j <= xf; j++){
                    if(i >= (bf + mf*j) && i <= (bm + mm*j))
                        img[i][j] = pixel;
                }
            }
            break;
        case 2:
            for(i = yC; i <= yA; i++){
                for(j = xi; j <= xm; j++){
                    if(i <= (bi + mi*j) && i >= (bm + mm*j)) 
                        img[i][j] = pixel; 
                }
            }
            for(i = yC; i <= yA; i++){
                for(j = xm; j <= xf; j++){
                    if(i <= (bf + mf*j) && i >= (bm + mm*j))
                        img[i][j] = pixel;
                }
            }
            break;
    }
    return;
}