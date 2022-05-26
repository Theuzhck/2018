#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Esta fun��o recebe uma lista encadeada le
// com cabe�a e insere na lista uma nova celula
// no final da lista. O conteudo da nova celula � 'add'.
// Ap�s isso a lista � invertida para ser impressa na
// mesma ordem em que foi preenchida.
// Em seguida � calculada e exibida a m�dia

struct reg  {
      float  conteudo;
      struct reg *prox;
   };

typedef struct reg celula;

celula *pi; // cabe�a da lista (global)
float _soma = 0; //  Soma das notas

void imprime (celula *le) { // impress�o da lista
	 celula *p;
	 int i = 0;
   for (p = le->prox; p != NULL; p = p->prox){
   		printf ("Nota %d: %.1f\n",i+1, p->conteudo);
   		++i;
   }
}

void inverte(celula *le) // invers�o da lista
{
    celula *q = le->prox;
    celula *pilha_aux = (celula *) malloc(sizeof(celula));
    celula *lixo; // ponteiro que vai apontar para os no's antigos que serao apagados.

    while(q != NULL)
    {
        insere(pilha_aux, q->conteudo);
        lixo = q;
        q = q->prox;
        _soma = lixo->conteudo + _soma;
        free(lixo);
    }


    le->prox = pilha_aux->prox;
    free(pilha_aux);
}

void insere (celula *le, float y) { // inser��o na lista
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->conteudo = y;
   nova->prox  = le->prox;
   le->prox = nova;
}

float media(float num){
    if (num != 0) return (_soma/num);
}

int main(void){ // principal
		int num;
		celula *pi = malloc(sizeof(celula));
	    pi->prox = NULL;

		scanf("%d", &num);
		if (num > 5 || num <=0) printf("Numero de notas invalido.");// Se num n�o estiver de acordo � rejeitado
		else{
				int i;
				for(i = 0; i < num; ++i){// os valores digitados s�o adicionados na lista
						float add = 0;
						scanf("%f", &add);
						insere(pi, add);
				}
		}
		inverte(pi); // a lista � invertida
		imprime(pi);// a lista � impressa
		if (num > 0 && num <= 5) printf("Media: %.2f",media(num));
		return 0;
}
