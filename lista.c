#include <stdio.h>

struct No {
    int numero;
    struct No *proximo;
};

int main() {
    int i;
    int numero;
    struct No* raizLista;

    for(i = 0; i < 5; i++) {
        printf("numero:");
        scanf("%d", &numero);
    
        // cria novo nó na memoria
        struct No* novoNo = (struct No*) malloc(sizeof(struct No));
        novoNo->numero = numero;
        novoNo->proximo = NULL;

        // se é o primeiro nó então raizLista aponta para ele
        if (i == 0) {
            raizLista = novoNo;
        } else {
            novoNo->proximo = raizLista;
            raizLista = novoNo;
        }       
    }

    struct No* noAtual = raizLista;
    for(i = 0; i < 5; i++) {
        printf("numero atual: %d", noAtual->numero);
        noAtual = noAtual->proximo;
    }
}