typedef struct reg {
      int  conteudo; // conteúdo
      noh *esq;
      noh *dir;
   } noh; // nó

typedef noh *arvore; // árvore

// Recebe a raiz r de uma árvore binária
// e imprime os conteúdos dos seus nós
// em ordem e-r-d.

void erd (arvore r) {
   if (r != NULL) {
      printf ("%d\n", r->conteudo);
      erd (r->esq);
      erd (r->dir);
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
    noh n10;

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

    n0.esq = "";
    n0.dir = "";

    n1.esq = &n0;
    n1.dir = &n2;

    n2.esq = "";
    n2.dir = "";

    n3.esq = &n1;
    n3.dir = &n4;

    n4.esq = "";
    n4.dir = "";

    n5.esq = &n3;
    n5.dir = &n8;

    n6.esq = "";
    n6.dir = &n7;

    n7.esq = "";
    n7.dir = "";

    n8.esq = &n6;
    n8.dir = &n9;

    n9.esq = "";
    n9.dir = "";



    return 0;
}
