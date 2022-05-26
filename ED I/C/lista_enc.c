//Esta função recebe uma lista encadeada le
// e imprime todos os valores da variável conteudo
// de cada uma das células da lista.
struct reg {
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

imprime(&c1);

return 0;
}
