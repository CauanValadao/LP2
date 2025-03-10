#include <FreeImage.h>
#include <stdio.h>

int main() {
    FreeImage_Initialise(FALSE);

    // Carregar a imagem de entrada
    FIBITMAP *image = FreeImage_Load(FIF_JPEG, "input.jpg", JPEG_DEFAULT);
    if (!image) {
        printf("Erro ao carregar a imagem.\n");
        return -1;
    }

    // Salvar a imagem no formato PNG
    if (FreeImage_Save(FIF_PNG, image, "output.png", PNG_DEFAULT)) {
        printf("Imagem convertida com sucesso!\n");
    } else {
        printf("Erro ao salvar a imagem.\n");
    }

    // Limpar memória
    FreeImage_Unload(image);
    FreeImage_DeInitialise();
    return 0;
}