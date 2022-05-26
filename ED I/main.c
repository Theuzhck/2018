#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//=======================
typedef struct reg2 noh;

typedef struct reg2 {
		int conteudo; // conteudo
		noh *esq;
		noh *dir;
} noh;

typedef noh *arvore; //árvore
//========================

typedef struct reg{
	arvore conteudo;
	struct reg *prox;
} celula;

arvore * cria_arv();

int altura_arv(arvore *r);

arvore * cria_arv(){
	arvore* r = (arvore*) malloc (sizeof(arvore));
	if (r != NULL)
	*r = NULL;
}

int altura_arv(arvore *r){
	if (r == NULL) return 0;
	if (*r == NULL) retrn 0;
	
	int alt_esq = altura_arv(&((*r)->esq));
	int alt_dir = altura_arv(&((*r)->dir));
	if (alt_esq > alt_dir) return (alt_esq + 1);
	else return (alt_dir + 1);
}

int main(int argc, char *argv[]) {
	arvore* r  = cria_arv();
	int x = altura_arv(r);
	
	return 0;
}
