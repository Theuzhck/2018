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

void busca_no(arvore r, int busca) {
   if (r != NULL) {
      busca_no(r->esq, busca);
      if (r->conteudo == busca)
          cont += 1;
      busca_no (r->dir, busca);
   }
}
void verifica (int busca){
    if (cont == 1){
        printf("O valor %d foi encontrado!", busca);
    }else{
        printf("O valor %d nao foi encontrado!", busca);
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

    int busca;
    scanf("%d", &busca);
    busca_no(&n5, busca);
    verifica(busca);
    return 0;
}
