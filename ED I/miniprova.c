#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct reg{
	int conteudo;
	struct reg *esq;
	struct reg *dir;
}noh;

typedef noh *arvore;

typedef struct reg2{
	arvore conteudo;
	struct reg *prox;
}celula;

arvore cria_no(int y);

int tiradafila (celula *fi);

celula *colocanafila (arvore y, celula *fi);

void nivel (int rec);

int main(void){
	celula *fi1, *fi2;
	fi1 = malloc (sizeof (celula));
	fi1->prox = fi1;
	
	fi2 = malloc (sizeof (celula));
	fi2->prox = fi2;
	
	arvore raiz, r;
	
	int elementos[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
	int n = sizeof(elementos)/sizeof(int);
	
	int i;
	for (i = 0; i < n; ++i){
		fi1 = colocanafila(cria_no(elementos[i]), fi1);
	}
		

	for (i = 1; i < n+1; ++i){
			r = tiradafila(fi1);
			fi2 = colocanafila(r, fi2);
			fi2 = colocanafila(r->esq, fi2);
			fi2 = colocanafila(r->dir, fi2);
			nivel(floor(log2(i)));
			printf("%d\n", r->conteudo);
			}
	
	return 0;
}

arvore cria_no(int y){
	noh *novo = malloc (sizeof(noh));
	novo->conteudo = y;
	novo->esq = novo->dir = NULL;
}

int tiradafila (celula *fi) {
   celula *p;
   p = fi->prox;  // o primeiro da fila
   arvore x = p->conteudo;
   fi->prox = p->prox;
   free (p);
   return x;  
}

celula *colocanafila (arvore y, celula *fi) { 
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->prox = fi->prox;
   fi->prox = nova;
   fi->conteudo = y;
   return nova;
}

void nivel (int rec){
	int i;
	for (i = 0; i < rec; ++i)
		printf("%s", "  ");
}
