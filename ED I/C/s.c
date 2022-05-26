#include <stdio.h>
#include <stdlib.h>
struct reg  {
      char  conteudo[50];
      struct reg *prox;
   };

typedef struct reg lista;

int main(){
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i){
      char c[50];
      scanf("%c", &c);
    }


    system("pause");
    return 0;
}
