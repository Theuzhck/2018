#include <stdio.h>

typedef struct reg noh;

typedef struct reg {
      int  conteudo; // conteúdo
      noh *esq;
      noh *dir;
   }  noh; // nó

typedef noh *arvore; // árvore

int cont = 0;

// Recebe a raiz r de uma árvore binária
// e imprime os conteúdos dos seus nós
// em ordem e-r-d.

void contagem(arvore r) {
   if (r != NULL) {
      contagem(r->esq);
      cont += 1;
      contagem (r->dir);
   }
}

int main(void){
    noh n1;
    noh n2;
    noh n3;
    noh n4;
    noh n5;
    noh n6;
    noh n7;
    noh n8;
    noh n9;
    noh n0;
    noh n11;


    n0.conteudo = 0;
    n1.conteudo = 1;
    n2.conteudo = 2;
    n3.conteudo = 3;
    n4.conteudo = 4;
    n5.conteudo = 5;
    n6.conteudo = 6;
    n7.conteudo = 7;
    n8.conteudo = 8;
    n9.conteudo = 9;


    n0.esq = NULL;
    n0.dir = NULL;

    n1.esq = &n0;
    n1.dir = &n2;

    n2.esq = NULL;
    n2.dir = NULL;

    n3.esq = &n1;
    n3.dir = &n4;

    n4.esq = NULL;
    n4.dir = NULL;

    n5.esq = &n3;
    n5.dir = &n8;

    n6.esq = NULL;
    n6.dir = &n7;

    n7.esq = NULL;
    n7.dir = NULL;

    n8.esq = &n6;
    n8.dir = &n9;

    n9.esq = NULL;
    n9.dir = NULL;

    n11.esq = NULL;
    n11.dir = NULL;

    contagem(&n5);
    printf("%d\n", cont);
    cont = 0;

    n11.conteudo = 11;
    n9.dir = &n11;
    n11.esq = NULL;
    n11.dir = NULL;

    contagem(&n5);
    printf("%d\n", cont);
    return 0;
}
