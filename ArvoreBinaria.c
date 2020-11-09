#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
  int numero;
  struct arvore* direita;
  struct arvore* esquerda;
} Arvore;

Arvore* criaArvore() {
  return NULL;
}

int arvoreVazia(Arvore* t) {
  return t == NULL;
}

void listaArvorePreOrdem(Arvore* t) {
  if(!arvoreVazia(t)) {
    printf("%d ", t->numero);
    listaArvorePreOrdem(t->esquerda);
    listaArvorePreOrdem(t->direita);
  }
}

void listaArvoreEmOrdem(Arvore* t) {
  if(!arvoreVazia(t)) {
    listaArvoreEmOrdem(t->esquerda);
    printf("%d ", t->numero);
    listaArvoreEmOrdem(t->direita);
  }
}

void listaArvorePosOrdem(Arvore* t) {
  if(!arvoreVazia(t)) {
    listaArvorePosOrdem(t->esquerda);
    listaArvorePosOrdem(t->direita);
    printf("%d ", t->numero);
  }
}

void insereArvore(Arvore** t, int numero) {
  if(*t == NULL) {
    *t = (Arvore*)malloc(sizeof(Arvore));
    (*t)->esquerda = NULL;
    (*t)->direita = NULL;
    (*t)->numero = numero;
  } else {

    if(numero < (*t)->numero) {
      insereArvore(&(*t)->esquerda, numero);
    }

    if(numero > (*t)->numero) {
      insereArvore(&(*t)->direita, numero);
    }
  }
}

int main() {

  Arvore* raiz = criaArvore();

  insereArvore(&raiz, 6);
  insereArvore(&raiz, 2);
  insereArvore(&raiz, 7);
  insereArvore(&raiz, 4);
  insereArvore(&raiz, 9);
  insereArvore(&raiz, 1);
  insereArvore(&raiz, 5);
  insereArvore(&raiz, 3);
  insereArvore(&raiz, 8);

  printf("\nPré Ordem\n");
  listaArvorePreOrdem(raiz);

  printf("\nEm Ordem (Simétrica\n");
  listaArvoreEmOrdem(raiz);

  printf("\nPós Ordem\n");
  listaArvorePosOrdem(raiz);

  free(raiz); /* Libera a memória alocada pela estrutura árvore */

  return 0;
}