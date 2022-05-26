#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct reg {
   char   conteudo[100]; 
   struct reg *prox;
} celula;

celula *fi;

celula *colocanafila (celula *fi, char texto[]) { 
   celula *nova;
   nova = (celula *) malloc (sizeof (celula));
   nova->prox = fi->prox;
   fi->prox = nova;
   strcpy(fi->conteudo, texto);
   return nova;
}
   
void imprime (celula *li) { // impressão da lista
     celula *p = li->prox;
     while(p != fi)
    {
        printf("%s\n", p->conteudo);
        p = p->prox;
    }
}

int main(void) {
  char entrada[] =  "Universidade Federal de Sergipe";
  char *token;
  
  fi = (celula *) malloc (sizeof (celula));
  fi->prox = fi;

  token = strtok(entrada, " ");

  while( token != NULL ) {
      fi = colocanafila(fi, token);
    
      token = strtok(NULL, " ");
   }

  imprime(fi);
  return 0;
}
