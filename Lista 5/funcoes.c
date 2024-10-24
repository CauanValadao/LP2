imgGray alocaImagemGray(int nLin, int nCol){
    imgGray *imagem = (imgGray*)malloc(sizeof(imgGray));
    if(imagem == NULL){
        imgGray imag;
        imag.img = NULL;
        imag._img = NULL;
        imag.nLin = nLin;
        imag.nCol = nCol;
        return imag;
    }
    
    imagem->nLin = nLin;
    imagem->nCol = nCol;
    
    imagem->_img = (uchar*)malloc(sizeof(uchar)*nLin*nCol);
    if(imagem->_img == NULL){
        imagem->img = NULL;
        return *imagem;
    }

    imagem->img = (uchar**)malloc(sizeof(uchar*)*nLin);
    if(imagem->img == NULL){
        free(imagem->_img);
        imagem->_img = NULL;
        return *imagem;
    }

    for(int i = 0; i < nLin; i++){
        imagem->img[i] = &imagem->_img[i*nCol];
    }

    return *imagem;
}

imgRGB alocaImagemRGB(int nLin, int nCol){
    imgRGB *imagem = (imgRGB*)malloc(sizeof(imgRGB));
    if(imagem == NULL){
        imgRGB imag;
        imag._img = NULL;
        imag.img = NULL;
        imag.nLin = nLin;
        imag.nCol = nCol;
        return imag;
    }

    imagem->_img = (tRGB*)malloc(sizeof(tRGB)*nLin*nCol);
    if(imagem->_img == NULL){
        imagem->img = NULL;
        return *imagem;
    }

    imagem->img = (tRGB**)malloc(sizeof(tRGB*)*nLin);
    if(imagem->img == NULL){
        free(imagem->_img);
        imagem->_img = NULL;
        return *imagem;
    }

    for(int i = 0; i < nLin; i++){
        imagem->img[i] = &imagem->_img[i*nCol];
    }

    return *imagem;
}

int geraImgGrayFull(imgGray img, uchar pixel){
    if(img.img == NULL || img._img == NULL) return 0;

    for(int i = 0; i < img.nCol*img.nLin; i++) img._img[i] = pixel;

    return 1;
}

int geraImgRGBFull(imgRGB img, tRGB pixel){
    if(img.img == NULL || img._img == NULL) return 0;

    for(int i = 0; i < img.nCol*img.nLin; i++){
        img._img[i].R = pixel.R;
        img._img[i].G = pixel.G;
        img._img[i].B = pixel.B;
    }

    return 1;
}

int geraImgGrayB(imgGray img){
    return geraImgGrayFull(img, 0);
}

int geraImgRGBB(imgRGB img){
    tRGB pixel;
    pixel.R = 0;
    pixel.G = 0;
    pixel.B = 0;
    return geraImgRGBFull(img, pixel);
}

int geraImgGrayW(imgGray img){
    return geraImgGrayFull(img, 255);
}

int geraImgRGBW(imgRGB img){
    tRGB pixel;
    pixel.R = 255;
    pixel.G = 255;
    pixel.B = 255;
    return geraImgRGBFull(img, pixel);
}

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

int geraImgGray(imgGray img, int tipo){
    if(img.img == NULL || img._img == NULL) return 0;

    for(int i = 0; i < img.nCol * img.nLin; i++){
        img._img[i] = geraPixelGrey(tipo);
    }
    return 1;
}

int geraImgRGB(imgRGB img, int tipo){
    if(img.img == NULL || img._img == NULL) return 0;

    for(int i = 0; i < img.nCol * img.nLin; i++){
        img._img[i].R = geraPixelGrey(tipo);
        img._img[i].G = geraPixelGrey(tipo);
        img._img[i].B = geraPixelGrey(tipo);
    }

    return 1;
}

int pixelGrayMax(imgGray img){
    if(img.img == NULL || img._img == NULL) return 256;

    int maior = img._img[0];

    for(int i = 0; i < img.nCol * img.nLin; i++){
        if(img._img[i] > maior) maior = img._img[i];
    }

    return maior;
}

int pixelGrayMin(imgGray img){
    if(img.img == NULL || img._img == NULL) return -1;

    int menor = img._img[0];

    for(int i = 0; i < img.nCol * img.nLin; i++){
        if(img._img[i] < menor) menor = img._img[i];
    }

    return menor;
}

tRGB pixelRGBMax(imgRGB img){
    if(img.img == NULL || img._img == NULL){
        tRGB erro;
        erro.R = -1;
        erro.G = -1;
        erro.B = -1;
        return erro;
    }

    tRGB maior;
    maior.R = img._img[0].R;
    maior.G = img._img[0].G;
    maior.B = img._img[0].B;

    for(int i = 0; i < img.nCol * img.nLin; i++){
        if(img._img[i].R > maior.R) maior.R = img._img[i].R;
        if(img._img[i].G > maior.G) maior.G = img._img[i].G;
        if(img._img[i].B > maior.B) maior.B = img._img[i].B;
    }

    return maior;
}

tRGB pixelRGBMin(imgRGB img){
    if(img.img == NULL || img._img == NULL){
        tRGB erro;
        erro.R = -1;
        erro.G = -1;
        erro.B = -1;
        return erro;
    }

    tRGB menor;
    menor.R = img._img[0].R;
    menor.G = img._img[0].G;
    menor.B = img._img[0].B;

    for(int i = 0; i < img.nCol * img.nLin; i++){
        if(img._img[i].R < menor.R) menor.R = img._img[i].R;
        if(img._img[i].G < menor.G) menor.G = img._img[i].G;
        if(img._img[i].B < menor.B) menor.B = img._img[i].B;
    }

    return menor;
}

int* somaPorLinhasGray(imgGray img){
    int *vet = (int*)calloc(sizeof(int),img.nLin);

    for(int i = 0; i < img.nLin; i++){
        for(int j = 0; j < img.nCol; j++)
            vet[i] += img.img[i][j];
    }
    return vet;
}

int* somaPorColunasGray(imgGray img){
    int *vet = (int*)calloc(sizeof(int), img.nCol);

    for(int j = 0; j < img.nCol; j++){
        for(int i = 0; i < img.nLin; i++)
            vet[j] += img.img[i][j];
    }
    return vet;
}
