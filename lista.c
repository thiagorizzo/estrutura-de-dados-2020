#include <stdio.h>
#include <locale.h>

struct No {
    int numero;
    struct No *proximo;
};

// variável global
struct No* raizLista; // primeiro nó da lista

int pesquisarLista(int numero) {
    struct No *noAtual = raizLista;
    int indice = 0;

    while(noAtual != NULL) {
        if (noAtual->numero == numero) {
            return indice;
        }
        noAtual = noAtual->proximo;
        indice++;
    }

    return -1;
}

void inserirListaInicio(int numero) {
    // cria na memória um novo nó
    struct No* novoNo = (struct No*) malloc(sizeof(struct No));
    novoNo->numero = numero;
    novoNo->proximo = NULL;

    if (raizLista == NULL) {
        raizLista = novoNo;
    } else {
        novoNo->proximo = raizLista;
        raizLista = novoNo;
    }
}

void inserirListaFinal(int numero) {
    // cria na memória um novo nó
    struct No* novoNo = (struct No*) malloc(sizeof(struct No));
    novoNo->numero = numero;
    novoNo->proximo = NULL;

   if (raizLista == NULL) {
       raizLista = novoNo;
   } else {
       struct No *noAtual = raizLista;
       // percorre lista até que noAtual esteja apontando 
       // para último nó
       while(noAtual->proximo != NULL) {
           noAtual = noAtual->proximo;
       }
    
       noAtual->proximo = novoNo;
   }
}

int removerLista(int numero) {
    int removeu = 0;

    if (raizLista == NULL) {
        printf("Lista vazia.");
    } else {
        struct No *noAnterior = NULL;
        struct No *noAtual = raizLista;

        while(noAtual != NULL) {
            if (noAtual->numero == numero) {
                noAnterior->proximo = noAtual->proximo;
                removeu = 1;
            }

            noAnterior = noAtual;
            noAtual = noAtual->proximo;
        }
    }

    return removeu;
}


int main() {
    setlocale(LC_ALL, "pt_BR_utf8");

    int numero;
    int opcao;
    int indice;
    int removeu;

    do {
        printf("Menu:\n\n");
        printf("1) inserir número no inicio.\n");
        printf("2) inserir número no final.\n");
        printf("3) listar números.\n");
        printf("4) pesquisar número.\n");
        printf("5) remover número.\n");
        printf("6) sair.\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("digite um número:");
                scanf("%d", &numero);
                inserirListaInicio(numero);
                break;

            case 2:
                printf("digite um número:");
                scanf("%d", &numero);
                inserirListaFinal(numero);
                break;                

            case 3:
                if (raizLista == NULL) {
                    printf("Lista está vazia.\n");
                } else {
                    struct No *noAtual = raizLista;
                    while(noAtual != NULL) {
                        printf("%d\n", noAtual->numero);
                        noAtual = noAtual->proximo;
                    }
                }
                break;
            
            case 4:
                printf("Digite número a pesquisar:");
                scanf("%d", &numero);
                indice = pesquisarLista(numero);
                if (indice == -1) {
                    printf("Número não foi encontrado.");
                } else {
                    printf("Número foi encontrado na posição: %d", indice);
                }
                break;
            
            case 5:
                printf("digite um número:");
                scanf("%d", &numero);
                removeu = removerLista(numero);
                if (removeu == 0) {
                    printf("Não foi possível remover número da lista.");
                }
                break;
        }
    } while(opcao != 6);
}