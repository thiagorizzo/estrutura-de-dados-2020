#include <stdio.h>
#include <locale.h>

#define TAMANHO_FILA 10

// analogia -> class Fila {
struct Fila {
    int elementos[TAMANHO_FILA];
    int indiceFinalFila;
};

// analogia -> Fila fila 
struct Fila fila;

int contagem() {
    return fila.indiceFinalFila + 1;
}

void inserirFila(int numero) {   
    if (contagem() == TAMANHO_FILA)
        printf("fila cheia.");
    else
    {
        fila.elementos[fila.indiceFinalFila] = numero;
        fila.indiceFinalFila++;
    }
}

void listarFila() {
    int i;
    for(i = 0; i < fila.indiceFinalFila; i++) {
        printf("%d\n", fila.elementos[i]);
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR_utf8");

    fila.indiceFinalFila = 0;

    int numero;
    int opcao;

    do {
        printf("Menu:\n\n");
        printf("1) inserir fila.\n");
        printf("2) listar fila.\n");
        printf("4) sair.\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("digite um número:");
                scanf("%d", &numero);
                inserirFila(numero);
                break;

            case 2:
                listarFila();
                break;   
        }
    } while(opcao != 4);
}

