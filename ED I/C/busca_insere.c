// Esta função recebe uma lista encadeada le
// com cabeça e insere na lista uma nova celula
// imediatamente antes da primeira que contém y.
// Se nenhuma celula contém y, insere a nova
// celula no fim da lista. O conteudo da nova
// celula é x.
#include <stdio.h>
#include <stdlib.h>

struct reg  {
      int         conteudo;
      struct reg *prox;
   };

typedef struct reg celula;

void imprime (celula *le) {
   if (le != "") {
      printf ("%d\n", le->conteudo);
      imprime (le->prox);
   }
}

void *mallocc (size_t nbytes)
{
   void *ptr;
   ptr = malloc (nbytes);
   if (ptr == "") {
      printf ("Socorro! malloc devolveu NULL!\n");
      exit (EXIT_FAILURE);
   }
   return ptr;
}

void
busca_e_insere (int x, int y, celula *le)
{
   celula *p, *q, *nova;
   nova = mallocc (sizeof (celula));
   nova->conteudo = x;
   p = le;
   q = le->prox;
   while (q != "" && q->conteudo != y) {
      p = q;
      q = q->prox;
   }
   nova->prox = q;
   p->prox = nova;
}

int main(void){
celula c1;
celula c2;
celula c3;
celula c4;
celula c5;
celula c6;

c1.conteudo = 10;
c2.conteudo = 20;
c3.conteudo = 30;
c4.conteudo = 40;
c5.conteudo = 50;
c6.conteudo = 60;

c1.prox = &c2;
c2.prox = &c3;
c3.prox = &c4;
c4.prox = &c5;
c5.prox = &c6;
c6.prox = "";

busca_e_insere(100, 80, &c1);

imprime(&c1);

return 0;
}

