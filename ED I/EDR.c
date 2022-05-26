#include <stdio.h>
#include <stdlib.h>



typedef struct reg {
  int conteudo;
  struct reg *pai;
  struct reg *esq;
  struct reg *dir;	
} noh;

typedef noh *arvore;

typedef struct fila {
   arvore conteudo; 
   struct fila *prox;
} celula;

void rec(arvore r, int b);

// Coloca um novo elemento com conteudo y
// na fila fi. Devolve o endereC'o da
// cabeC'a da fila resultante.

celula *colocanafila (arvore y, celula *fi) 
{ 
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->prox = fi->prox;
   fi->prox = nova;
   fi->conteudo = y;
   return nova;
}

// Tira um elemento da fila fi e devolve
// o conteudo do elemento removido.
// SupC5e que a fila nC#o estC! vazia.

arvore tiradafila (celula *fi) 
{
   celula *p;
   p = fi->prox;
   arvore x = p->conteudo;
   fi->prox = p->prox;
   free (p);
   return x;  
}

// Recebe a raiz r de uma C!rvore binC!ria e
// o valor do conteudo. Cria e retorna
// uma nova folha da C!rvore binC!ria.

arvore crianoh (arvore r, int k) 
{
    noh *novo;
    novo = malloc (sizeof (noh));
    novo->conteudo = k;
    novo->esq = novo->dir = NULL;
	novo->pai = NULL;
	return novo;
}

// A funC'C#o recebe uma C!rvore de busca r
// e uma folha avulsa novo e insere a folha
// na C!rvore de modo que a C!rvore continue
// sendo de busca. A funC'C#o devolve a raiz 
// da C!rvore resultante.

arvore insere (arvore r, noh *novo) {  
    if (r == NULL) return novo;
    if (r->conteudo > novo->conteudo) 
       r->esq = insere (r->esq, novo);
    else 
       r->dir = insere (r->dir, novo);
    return r;
}


void insere_pai (arvore r){
   if(r->esq != NULL) {
       r->esq->pai = r;
       insere_pai(r->esq);
   }
     if(r->dir != NULL){
       r->dir->pai = r;  
       insere_pai(r->dir);
     } 
}

void imprime_recuo(arvore x, int b) {
    if(x != NULL){
        imprime_recuo(x->esq, b+1);
        imprime_recuo(x->dir, b+1);
				rec(x, b);
    }
		if (x == NULL) {rec('-', b);}    
}

void rec(arvore r, int b) {
    int i;
    for (i = 0; i < b; i++) 
        printf("   ");
    if (r == (arvore) '-') printf("-\n");
    
    else printf("%d\n", r->conteudo);
}




int main(void){
  celula *fi;
  fi = malloc(sizeof(celula));
  fi->prox = fi;
  int i;
  int elementos[] = {4, 2, 6, 1, 3, 5, 7};
  int n = sizeof(elementos)/sizeof(int);
  int resp[n];
  
  arvore raiz = NULL;
  
  for (i = 0; i < n; ++i) {
		arvore a = crianoh(raiz, elementos[i]);
		raiz =  insere(raiz, a);
	}

  insere_pai(raiz);
	imprime_recuo(raiz, 0);
  
  return 0;	
}
