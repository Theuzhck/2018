#include <stdio.h>

typedef struct reg noh;

typedef struct reg {
      int  conteudo; // conteúdo
      noh *esq;
      noh *dir;
   }  noh; // nó

typedef noh *arvore; // árvore

// Essa função em conjunto com a função print imprimem uma árvore binária.
// A função imprime_recuo faz a varredura r-e-d até quando o nó visitado for nulo,
// quando isso acontecer será impresso '-' com o recuo necessário.

void imprime_recuo(arvore x, int b) {
    if (x == NULL) {
        esp('-', b);
        return;
    }
    esp(x, b);
    imprime_recuo(x->esq, b+1);    
    imprime_recuo(x->dir, b+1);     
}

// A função esp recebe um nó a ser visitado e a 'profundidade' desse nó.
// E imprime a qtd necessária de espaços em branco para o nó em questão

void esp(arvore r, int b) {
    int i;
    for (i = 0; i < b; i++) 
        printf("   ");
    if (r == '-') printf("-\n");
    else printf("%d\n", r->conteudo);
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


    n1.conteudo = 111;
    n2.conteudo = 333;
    n3.conteudo = 444;
    n4.conteudo = 555;
    n5.conteudo = 888;
    n6.conteudo = 999;


    n1.esq = NULL;
    n1.dir = NULL;

    n2.esq = &n1;
    n2.dir = &n3;

    n3.esq = NULL;
    n3.dir = NULL;

    n4.esq = &n2;
    n4.dir = &n5;

    n5.esq = NULL;
    n5.dir = &n6;

    n6.esq = NULL;
    n6.dir = NULL;

    imprime_recuo(&n4, 0);
    return 0;
}
