
/*Funcao 1*/
unsigned char* alocaImagem1D(int nLin, int nCol){
    unsigned char* img = (unsigned char*)malloc(sizeof(unsigned char)*nLin*nCol);

    if(img == NULL){
        printf("Alocacao falhou");
        exit(0);
    }

    return img;
}

/*Funcao 2*/
unsigned char** alocaImagem2D(unsigned char** img1D, int nLin, int nCol){
    *img1D = alocaImagem1D(nLin, nCol);
    unsigned char** img2D = (unsigned char**)malloc(sizeof(unsigned char*)*nLin);

    if(img2D == NULL){
        printf("Alocacao falhou");
        exit(0);
    }

    for(int i = 0; i < nLin; i++)
        img2D[i] = &(*img1D)[i*nCol];
    return img2D;
}

/*Funcao 3*/
void geraImgGreyFull_D1(unsigned char* img, int nLin, int nCol, unsigned char pixel){
    for(int i = 0; i < nLin*nCol; i++)
        img[i] = pixel;
}

/*Funcao 4*/
void geraImgGreyFull_D2(unsigned char** img, int nLin, int nCol, unsigned char pixel){
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++)
            img[i][j] = pixel;
    }
}

/*Funcao 5*/
void geraImgGreyB_D2(unsigned char** img, int nLin, int nCol){
    geraImgGreyFull_D2(img, nLin, nCol, 0);
}

/*Funcao 6*/
void geraImgGreyB_D1(unsigned char* img, int nLin, int nCol){
    geraImgGreyFull_D1(img, nLin, nCol, 0);
}

/*Funcao 7*/
void geraImgGreyW_D2(unsigned char** img, int nLin, int nCol){
    geraImgGreyFull_D2(img, nLin, nCol, 255);
}

/*Funcao 8*/
unsigned char geraPixelGrey(int tipo){

    int prob, valor;

    prob = rand() % 100;

    if(tipo < 0){
        if(prob < 80) valor = rand() % 128;
        
        else valor = rand() % 256;
    }
    else if(tipo > 0){
        if(prob < 80) valor = rand() % 128 + 128;

        else valor = rand() % 256;
    }
    else valor = rand() % 256;

    return (unsigned char) valor;
}

void geraImgGrey_D(unsigned char** img, int nLin, int nCol, int tipo){
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++)
            img[i][j] = geraPixelGrey(tipo);
    }
}

/*Funcao 9*/
int pixelMax_D(unsigned char** img, int nLin, int nCol){
    int maior = img[0][0];
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++)
            if(img[i][j] > maior) maior = img[i][j];   
    }
    return maior;
}

/*Funcao 10*/
int pixelMin_D(unsigned char** img, int nLin, int nCol){
    int min = img[0][0];
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++)
            if(img[i][j] > min) min = img[i][j];   
    }
    return min;  
}

/*Funcao 11*/
int* somaPorLinhas_D(unsigned char** img, int nLin, int nCol){
    int* soma = (int*)malloc(sizeof(int)*nLin);
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++) soma[i] += img[i][j];
    }
    return soma;
}

/*Funcao 12*/
int* somaPorColunas_D(unsigned char** img, int nLin, int nCol){
    int* soma = (int*)malloc(sizeof(int)*nCol);
    for(int j = 0; j < nCol; j++){
        for(int i = 0; i < nLin; i++) soma[j] += img[i][j];
    }
    return soma;
}

/*Funcao 13*/
int somaTotal_R(unsigned char** img, int nLin, int nCol){
    int soma = 0;
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++) soma += img[i][j];
    }
    return soma;
}

/*Funcao 14*/
int quantosPixelsNaInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten){
    int quant = 0;
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            if(img[i][j] == inten) quant++;
        }
    }
    return quant;
}

/*Funcao 15*/
int quantosPixelsAbaixoDeInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten){
    int abaixo = 0;
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++)
            if(img[i][j] < inten) abaixo++;
    }
    return abaixo;
}

/*Funcao 16*/
int quantosPixelsAcimaDeInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten){
    return nLin*nCol - quantosPixelsAbaixoDeInt_D(img, nLin, nCol, inten) - quantosPixelsNaInt_D(img, nLin, nCol, inten);
}