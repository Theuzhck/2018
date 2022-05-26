#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int altura(arvore r);

int completa(arvore r);

int profundidade(int elementos[], int busca, int n);

// Coloca um novo elemento com conteudo y
// na fila fi. Devolve o endereço da
// cabeça da fila resultante.

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
// Supõe que a fila não está vazia.

arvore tiradafila (celula *fi) 
{
   celula *p;
   p = fi->prox;
   arvore x = p->conteudo;
   fi->prox = p->prox;
   free (p);
   return x;  
}

// Recebe a raiz r de uma árvore binária e
// o valor do conteudo. Cria e retorna
// uma nova folha da árvore binária.

arvore crianoh (arvore r, int n) 
{
  r = malloc(sizeof(arvore));
  r->conteudo = n;
  r->esq = NULL;
  r->dir = NULL;
  return r;
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

// A função esp recebe um nó a ser visitado e a 'profundidade' desse nó.
// E imprime a qtd necessária de espaços em branco para o nó em questão

void rec(arvore r, int b) {
    int i;
    for (i = 0; i < b; i++) 
        printf("   ");
    if (r == '-') printf("-\n");
    else printf("%d\n", r->conteudo);
}


int main(void) 
{
  celula *fi;
  fi = malloc(sizeof(celula));
  fi->prox = fi;
  int i;
  int elementos[] = {5, 4, 23678,35, 756,2345, 543,6787, 2546,526, 675, 4356, 78654};

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

  if (completa(raiz)) printf("E balanceada\n");
	else (printf("Nao e balanceada\n"));

	printf("%d\n", profundidade(elementos, 543, n));



  return 0;	
}

int completa(arvore r){
	if (r == NULL) return 1;
	else if (r->esq == NULL && r->dir==NULL) /* r não tem filhos */
		return 1;
	else if (r->esq!=NULL && r->dir!=NULL) /* r tem ambas subárvores não-nulas */
		return (completa(r->esq) && completa(r->dir)); /* recursão */
	else if (r->esq != NULL) /* tem um único filho – `a esquerda */
		return (altura(r->esq) == 1);
	else /* tem um único filho – `a direita */
		return (altura(r->esq) == 1); 
}

int altura(arvore r){
	if (r == NULL) return 0;
	int altE = altura(r->esq);
	int altD = altura(r->dir);

	if (altE > altD) return (altE + 1);
	else return (altD + 1); 
}

// Recebe o vetor elementos, o valor a ser buscado e o tamanho do vetor.
// Ele busca o valor no vetor até encontrá-lo. Depois enc recebe a posição do valor busca
// A partir daí é calculado o nível onde o nó está, a partir da posição do valor dele no vetor
// Antes do retorno é acrescentado 1 à posição encontrada para que seja considerada a contagem a partir de 1 e não de 0, para não dar erro.
// E retorna -1 caso não encontre o elemento.

int profundidade(int elementos[], int busca, int n){
	 int enc = 0, i, rec = -1;
   for (i = 0; i < n; ++i) {
		 if (busca == elementos[i]){
				enc = i;
		 }
	 }
	 rec = floor(log2(enc+1));
	 return rec;
}
