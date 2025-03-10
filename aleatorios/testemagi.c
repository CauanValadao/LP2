#include <wand/MagickWand.h>

int main(int argc, char **argv) {
    // Inicializar o ambiente do MagickWand
    MagickWandGenesis();

    // Criar um MagickWand
    MagickWand *wand = NewMagickWand();

    // Carregar a imagem de entrada
    if (MagickReadImage(wand, "input.jpg") == MagickFalse) {
        printf("Erro ao carregar imagem!\n");
        return 1;
    }

    // Salvar como outra extensão
    if (MagickWriteImage(wand, "output.png") == MagickFalse) {
        printf("Erro ao salvar imagem!\n");
        return 1;
    }

    // Liberar memória
    wand = DestroyMagickWand(wand);
    MagickWandTerminus();

    printf("Conversão concluída com sucesso!\n");
    return 0;
}