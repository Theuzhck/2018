#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLACK false
#define RED true

typedef struct reg {
  char conteudo;
  struct reg *esq;
  struct reg *dir;	
	int n;
	bool cor;
} noh;

typedef noh *arvore;

arvore put(arvore r, char val);

bool isRed(arvore x) {
	if (x == NULL) return false;
	return x->cor == RED;
}	

int size(arvore x){
	if (x == NULL) return 0;
	else return (1+ size(x->esq) + size(x->dir));
}

arvore rotateLeft(arvore h) {
	arvore x = h->dir;
	h->dir = x->esq;
	x->esq = h;
	x->cor = h->cor;
	h->cor = RED;
	x->n = h->n;
	h->n = 1 + size(h->esq) + size(h->dir);
	return x;
}

 arvore rotateRight(arvore h) {
	arvore x = h->esq;
	h->esq = x->dir;
	x->dir = h;
	x->cor = h->cor;
	h->cor = RED;
	x->n = h->n;
	h->n = 1 + size(h->esq) + size(h->dir);
	return x;
}

void flipColors(arvore h) {
	h->cor = RED;
	h->esq->cor = BLACK;
	h->dir->cor = BLACK;
}

arvore put_raiz(char val) { 
	arvore root = NULL;
	root = put(root, val);
	root->cor = BLACK;
	return root;
}

arvore put(arvore r, char val){
	if (r==NULL){
		noh *novo;
    novo = malloc (sizeof (noh));
    novo->conteudo = val;
    novo->esq = novo->dir = NULL;
		novo->cor = RED;
		return novo;
	}

	if(val < r->conteudo) r->esq = put(r->esq, val);
  else if (val > r->conteudo) r->dir = put(r->dir, val);

	if (isRed(r->dir) && !isRed(r->esq))      r = rotateLeft(r);
	if (isRed(r->esq)  &&  isRed(r->esq->esq)) r = rotateRight(r);
	if (isRed(r->esq)  &&  isRed(r->dir))     flipColors(r);
	r->n = 1 + size(r->esq) + size(r->dir);
	return r;
}

void verifica_raiz(arvore raiz){
	raiz->cor = BLACK;
}

void imprime_recuo(arvore x, int b) {
    if (x == NULL) {
        rec('-', b);
        return;
    }
    rec(x, b);
    imprime_recuo(x->esq, b+1);    
    imprime_recuo(x->dir, b+1);     
}

void rec(arvore r, int b) {
    int i;
    for (i = 0; i < b; i++) 
        printf("   ");
    if (r == '-') printf("-\n");
    else {
        if ((r->cor == RED)) printf("%c* \n", r->conteudo);
        else if(r->cor == BLACK) printf("%c \n", r->conteudo);
    }
}

void limpa(arvore raiz){
	raiz->conteudo = NULL;
	raiz->cor = NULL;
	raiz->dir = raiz->esq = NULL;
	raiz->n = 0;
}

int main(void) {
  
  int i, j;
  char elementos[11] = {'Y', 'L', 'P', 'M', 'X', 'H', 'C', 'R', 'A', 'E', 'S'};
  char ele[10] = {'E', 'A', 'S', 'Y', 'Q', 'U', 'T', 'I', 'O', 'N'};
  int qtd = sizeof(elementos)/sizeof(char);
  int qtd2 = sizeof(ele)/sizeof(char);
  
  arvore raiz = put_raiz(elementos[0]);

	for (i=1; i < qtd; ++i){
		raiz = put(raiz, elementos[i]);
	}
	verifica_raiz(raiz);
  printf("Primeira arvore:\n");
  imprime_recuo(raiz, 0);
  
  limpa(raiz);
  printf("_____________________\n");
  printf("Segunda arvore:\n");
  raiz = put_raiz(ele[0]);
  for (j=1; j < qtd2; ++j){
		raiz = put(raiz, ele[j]);
	}
	verifica_raiz(raiz);

  imprime_recuo(raiz, 0);
  printf("_____________________\n");


  return 0;
}
