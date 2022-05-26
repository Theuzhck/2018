#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Esta função recebe uma lista encadeada le
///////////////////////////
/////////////////////
////////////////////////
////////////////////////////

typedef struct reg  {
      float  conteudo;
      struct reg *prox;
   } celula;

celula *pi; // cabeça da lista (global)

void imprime (celula *le) { // impressão da lista
	 while (le != NULL){
	 	printf ("%c\n", le->conteudo);
	 }
   	 	
}

void empilha (char y) { 
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->conteudo = y;
   nova->prox  = pi->prox;
   pi->prox = nova; 
}

char desempilha (void) {
   celula *p;
   p = pi->prox;
   char x = p->conteudo;
   pi->prox = p->prox;
   free (p);
   return x; 
}

void criapilha (void) {
   pi = malloc (sizeof (celula)); // cabeça
   pi->prox = NULL; 
}

int main(void){ // principal
		int num;
		char a = 'a', b = 'b', c = 'c';
		
		criapilha();
		
		empilha(a);
		empilha(b);
		empilha(c);
		
		imprime(pi);
		printf("Remove: %c", desempilha());
		return 0;
}

