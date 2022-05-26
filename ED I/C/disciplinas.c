#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Este programa recebe 4 n?meros inteiros e os adiciona
// em uma lista encadeada pela ordem do maior para o menor
// e depois imprime essa lista.

struct reg  {
      char  conteudo[20];
      struct reg *prox;
   };

typedef struct reg celula;

void insere (celula *le, char y[20]) { // inserção na lista
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->conteudo[20] = y[20];
   nova->prox  = le->prox;
   le->prox = nova;
}
/*
void insere(celula **p) // inser??o dos valores na lista
{
    celula *atual, *novo, *anterior;
    char nome[20];

    novo = (celula *) malloc(sizeof(celula));
    atual = *p;
    anterior = NULL;

    scanf("%s", &nome);
    novo->conteudo[20] = nome[20];

    if(atual == NULL){
        novo->prox = NULL;
        *p = novo;
    } else{
        while(atual != NULL){
            anterior = atual;
            atual = atual->prox;
        }

        novo->prox = atual;

        if(anterior == NULL){
            *p = novo;
        } else{
            anterior->prox = novo;
        }
    }
}*/

celula *busca (char x[], celula *le)
{
   celula *p;
   p = le;
   while (p != NULL && p->conteudo != x) 
      p = p->prox; 
   return p; 
}
int profundidade (char c[], celula *le)
{
    int cont = 0;
    celula *p;
    p = le;
    while (p->conteudo != c) {
        cont += 1;
        p = p->prox;
    }
    return cont+1;
}

void imprime (celula *le) { // impressão da lista
	 celula *p = le;
	 while(p != NULL)
    {
        printf("Valor: %d\n", p->conteudo);
        p = p->prox;
    }
}

int altura (char x[], celula *le)
{
    int cont = 0;
    celula *p;
    p = le;
    while (p->prox != NULL) {
        if (cont > 0){
            cont += 1;
            p = p->prox;
        }
        if (p->conteudo == x){
            cont += 1;
            p = p->prox;
        }else if (p->conteudo != x) p = p->prox;
    }
    return cont+1;
}

//char falta(char c[], celula *le){
//	while (c != le->conteudo){
//		printf("%s ", le->conteudo);
//	}
//}

int main(void)
{
		int i = 0, num;
    	celula *pi = NULL;/*
		scanf("%d", &num);
    for (i = 0; i < num; ++i){
        insere(&pi);
    }*/
		celula c1, c2,c3,c4;
		//scanf("%s", &c1);
		insere(pi, "Calculo 1");
		insere(pi, "Calculo 2");
		insere(pi, "Calculo 3");
		insere(pi, "Calculo 4");
		//c1.conteudo[20] = (char) "Calculo 1";
		//insere(&pi, c1);
		//scanf("%s", &c2);
		//c2.conteudo[20] = (char)"Calculo 2";
		//insere(&pi, c2);
		//scanf("%s", &c3);
		//c3.conteudo[20] = (char)"Calculo 3";
		//insere(&pi, c3);
		//scanf("%s", &c4);
		//c4.conteudo[20] = (char) "Calculo 4";
		//insere(&pi, c4);
		imprime(pi);

		for (i = 0; i < num; ++i){
				char disc[20];
				scanf("%s", disc);
        if(busca(disc, pi) == NULL) 
					printf("%s nao pode ser cursada nessa cadeia de pre-requisitos.", disc);
				else if(profundidade(disc, pi) == 1)
					printf("%s podera ser cursada esse per?odo.", disc);
				else 
					printf("%s podera ser cursada depois de %d periodos, depois de ter passado por:.", disc, altura(disc, pi) /*falta(disc, pi)*/);
        }
	
    
		
    return 0;
}
