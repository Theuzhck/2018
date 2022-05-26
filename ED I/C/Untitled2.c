// FILA EM LISTA ENCADEADA
typedef struct reg {
   int         conteudo; 
   struct reg *prox;
} celula;


// Coloca um novo elemento com conteudo y
// na fila fi. Devolve o endereço da
// cabeça da fila resultante.

void *colocanafila (int y, celula *fi) { 
   celula *nova;
   nova = (celula *)  malloc (sizeof (celula));
   nova->prox = fi->prox;
   fi->prox = nova;
   fi->conteudo = y;
}


void intercala(celula *f1, celula *f2, int k){
	celula *res;
	if (k == 1){
		res->conteudo = f1;
		res->prox = f2;
		intercala(f1->prox, f2->prox, k);
	}else if (k == 2){
		res->conteudo = f2;
		res->prox = f1;
		intercala(f1->prox, f2->prox, k);
	}
}

void imprime (celula *li) { // impressão da lista
     celula *p = li->prox;
     while(p != "")
    {
        printf("%s\n", p->conteudo);
        p = p->prox;
    }
}

int main(void){
	celula *f1, *f2;
	f1 = (celula *) malloc (sizeof (celula));
  	f1->prox = "";
  	f2 = (celula *) malloc (sizeof (celula));
  	f2->prox = "";
	int n, m, k, i, j;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i>n; i++){
		int n1;
		scanf("%d", n1);
		colocanafila(n1, f1);
	}
	
	for(j = 0; j>m; j++){
		int n1;
		scanf("%d", n1);
		colocanafila(n1, f2);
	}
	imprime(f1);
	imprime(f2);
}


