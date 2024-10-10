

unsigned char geraGreyPixel (int tipo) {
    unsigned char num;
    int probabilidade = rand() % 100;
    if(tipo < 0){
       if (probabilidade < 80)      //80% de chance de cor escura
            num = rand() % 128;
       else                        //20% de chance de todas as cores
            num = rand() % 256;
    }
    else if (tipo > 0) {
        if (probabilidade < 80)             //80% de chance de cor clara
            num = 128 + rand() % 128;       
        else                            //20% de chance de todas as cores
            num = rand() % 256;
    }
    else
        num = rand() % 256;          //100% de chance de todas as cores
    return num;
}

unsigned char* geraArray1D(int tam){
    return (unsigned char*)malloc(sizeof(unsigned char) * tam);
}   

unsigned char** geraArray2D(int nLin, int nCol){
    unsigned char **mat;
    mat = (unsigned char**)malloc(sizeof(unsigned char*)*nLin);
    for(int i = 0; i < nLin; i++){
        mat[i] = (unsigned char*)malloc(sizeof(unsigned char)*nCol);
    }
    return mat;
}

void geraImgGreyFull_D(unsigned char **img, int nLin, int nCol, unsigned char pixel){
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            img[i][j] = pixel;
        }
    }
}

void geraImgGreyB_D(unsigned char** img, int nLin, int nCol){
    geraImgGreyFull_D(img, nLin, nCol, 0);
}

void geraImgGreyW_D(unsigned char** img, int nLin, int nCol){
    geraImgGreyFull_D(img, nLin, nCol, 255);
}

void geraImgGrey_D(unsigned char** img, int nLin, int nCol, int tipo){
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            img[i][j] = geraGreyPixel(tipo);
        }
    }
}

int pixelMax_D(unsigned char** img, int nLin, int nCol){
    int max = img[0][0];
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            if(max < img[i][j]) max = img[i][j];
        }
            
    }
    return max;
}

int pixelMin_D(unsigned char** img, int nLin, int nCol){
    int min = img[0][0];
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            if(min > img[i][j]) min = img[i][j];
        }
            
    }
    return min;
}

int* somaPorLinhas_D(unsigned char** img, int nLin, int nCol){
    int i, j, *soma = (int*)calloc(nLin, sizeof(int));
    for(i = 0; i < nLin; i++){
        for(j = 0; j < nCol; j++){
            soma[i] += img[i][j];    
        }
    }
    return soma;
}

int* somaPorColunas_D(unsigned char** img, int nLin, int nCol){
    int i, j, *soma = (int*)calloc(nCol, sizeof(int));
    for(i = 0; i < nLin; i++){
        for(j = 0; j < nCol; j++){
            soma[j] += img[i][j];    
        }
    }
    return soma;
}

int somaTotal_R(unsigned char** img, int nLin, int nCol){
    int soma = 0, i, j;

    for(i = 0; i < nLin; i++){
        for(j = 0; j < nCol; j++)
            soma += img[i][j];
    }
    return soma;
}

int quantosPixelsNaInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten){
    int quant = 0, i, j;

    for(i = 0; i < nLin; i++){
        for(j = 0; j < nCol; j++){
            if(img[i][j] == inten)
                quant++;
        }
    }
    return quant;
}

int quantosPixelsAbaixoDeInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten){
    int quant = 0, i, j;

    for(i = 0; i < nLin; i++){
        for(j = 0; j < nCol; j++){
            if(img[i][j] < inten)
                quant++;
        }
    }
    return quant;
}

int quantosPixelsAcimaDeInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten){
    return nLin*nCol - quantosPixelsNaInt_D(img, nLin, nCol, inten) - quantosPixelsAbaixoDeInt_D(img, nLin, nCol, inten);
}