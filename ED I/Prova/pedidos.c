#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg {
   int   conteudo; 
   struct reg *prox;
} celula;

// Esta fun??o insere os pedidos na lista
void insere (int x, celula *le){
   celula *p, *q, *nova;
   nova = malloc (sizeof (celula));
   nova->conteudo = x;
   p = le;
   q = le->prox;
   while (q != NULL) {
      p = q;
      q = q->prox;
   }
   nova->prox = q;
   p->prox = nova;
}

//Essa fun??o remove o pedido da lista
void remover (int y, celula *le)
{
   celula *p, *q;
   p = le;
   q = le->prox;
   while (q != NULL && q->conteudo != y) {
      p = q;
      q = q->prox;
   }
   if (q != NULL) {
      p->prox = q->prox;
      free (q);
			printf("removido\n");
   }else if (q == NULL){
		 printf("falha\n");
	 }
   
}

// Esta fun??o imprime todos os pedidos da lista;
// Enquanto n?o for o ?limo pedido, a fun??o imprime um espa?o entre os pedidos;
// Quando for o ?ltimo pedido ser? impresso uma quebra de linha;
// E se a lista a ser impressa estiver vazia a fun??o imprime "vazia".
int imprime (celula *le) {
   celula *p = le->prox;
   celula *q;
   if (p != NULL){
      q = p->prox;
      printf ("%d", p->conteudo);
			if (q != NULL)
				printf(" ");
      imprime (le->prox);
   }
   if(le->conteudo != 0 && p == NULL){
      printf("\n");
      return 0;
   }
   if (le->conteudo == 0 && p == NULL) {
      printf("vazia\n");
      return 0;
   }
      
}

int main(void){
    char acao;
    int pedido, rem;
    celula fi;
    fi.conteudo = 0;
    fi.prox = NULL;
  
		while(1){
			scanf ("%c", &acao);
			if (acao == 'p'){
            imprime(&fi);
      }else if( acao == 'a'){
            scanf("%d", &pedido);
            insere(pedido, &fi);
      }else if ( acao == 'r'){
            scanf("%d", &rem);
            remover(rem, &fi);
      }else if( acao == 's'){
						break;
			}
		}
    
    return 0;
}
