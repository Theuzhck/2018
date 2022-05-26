#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
  int conteudo;
  struct reg *esq;
  struct reg *dir;	
} noh;

typedef noh *arvore;

typedef struct fila {
   arvore conteudo; 
   struct fila *prox;
} celula;

void rec(arvore r, int b);

int min = 999999999;
int max = 0;

// Coloca um novo elemento com conteudo y
// na fila fi. Devolve o endere�o da
// cabe�a da fila resultante.

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
// Sup�e que a fila n�o est� vazia.

arvore tiradafila (celula *fi) 
{
   celula *p;
   p = fi->prox;
   arvore x = p->conteudo;
   fi->prox = p->prox;
   free (p);
   return x;  
}

// Recebe a raiz r de uma �rvore bin�ria e
// o valor do conteudo. Cria e retorna
// uma nova folha da �rvore bin�ria.

arvore crianoh (arvore r, int n) 
{
  r = malloc(sizeof(arvore));
  r->conteudo = n;
  r->esq = NULL;
  r->dir = NULL;
  return r;
}

arvore minimo(arvore x) {
    if (x->esq == NULL) return x;
		if (x->conteudo < min){
			min = x->conteudo;
			minimo(x->esq);
		}
}

arvore maximo(arvore x){
	if (x->dir == NULL) return x;
	if (x->conteudo > max){
		max = x->conteudo;
		maximo(x->dir);
	}
}

int busca(arvore x) {
		if (x == NULL) return 1;
		if ((x->esq == NULL) && (x->dir == NULL)) return 1;
    if ((x->esq->conteudo <= x->conteudo) && (x->dir->conteudo >= x->conteudo)) {
        busca(x->esq);
				busca(x->dir);
    }else return 0;
}

int main(void) 
{
  celula *fi;
  fi = malloc(sizeof(celula));
  fi->prox = fi;
  int i;
  int elementos[] = {4, 2, 6, 1, 3, 5, 7};

	int n = sizeof(elementos)/sizeof(int);
  
  arvore raiz, x;
  raiz = crianoh(raiz, elementos[0]);
  fi = colocanafila(raiz, fi);
  
  for (i = 1; i < n; i += 2) {
    x = tiradafila(fi);
    x->esq = crianoh(x->esq, elementos[i]);
    x->dir = crianoh(x->dir, elementos[i+1]);
    fi = colocanafila(x->esq, fi);
    fi = colocanafila(x->dir, fi);
  }
  if (busca(raiz)) printf("� uma �rvore de busca.\n");
	else printf("N�o � uma �rvore de busca.\n");

	printf("M�ximo: %d; \nM�nimo: %d;", maximo(raiz)->conteudo,minimo(raiz)->conteudo);
	
  return 0;	
}