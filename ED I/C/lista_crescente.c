// Esta função recebe uma lista encadeada le
// com cabeça e busca um valor x nessa lista
// e a partir da primeira celula  até a
// celula com conteudo x é contada a qtde de passos.
// É retornada essa qtde de passos.
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


int crescente(celula *le)
{
    int cresce = 1;
    celula *p = le->prox;
    if (p == "")  return cresce;
    if (le->conteudo < p->conteudo ) return crescente (le->prox);
    else return 0;
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
c5.prox = &c6;
c4.prox = &c5;
c6.prox = "";

printf("%d\n",crescente(&c1));

imprime(&c1);

return 0;
}




