// Esta função recebe uma lista encadeada le
// com cabeça e remove da lista a primeira
// celula que contiver y, se tal celula existir.

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

void
busca_e_remove (int y, celula *le)
{
   celula *p, *q;
   p = le;
   q = le->prox;
   while (q != "" && q->conteudo != y) {
      p = q;
      q = q->prox;
   }
   if (q != "") {
      p->prox = q->prox;
      free (q);
   }
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

busca_e_remove(40, &c1);

imprime(&c1);

return 0;
}
