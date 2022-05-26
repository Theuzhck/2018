Projeto de Algoritmos   |   Linguagem C   |   Índice

Alocação dinâmica de memória
As declarações abaixo alocam espaço de memória para diversas variáveis. A alocação é estática (nada a ver com a palavra-chave static), ou seja, acontece antes que o programa comece a ser executado:

char c; 
int i; 
int v[10]; 
Em muitas aplicações, a quantidade de memória a alocar só se torna conhecida durante a execução do programa. Para lidar com essa situação é preciso recorrer à alocação dinâmica de memória. A alocação dinâmica é administrada pelas funções malloc, realloc e free, que estão na biblioteca stdlib.  Para usar essa biblioteca, inclua a correspondente interface no seu programa:

#include <stdlib.h>
A função malloc
A função  malloc  (o nome é uma abreviatura de memory allocation) aloca espaço para um bloco de bytes consecutivos na memória RAM (= random access memory) do computador e devolve o endereço desse bloco.  O número de bytes é especificado no argumento da função. No seguinte fragmento de código, malloc aloca 1 byte:

char *ptr;
ptr = malloc (1);
scanf ("%c", ptr);
O endereço devolvido por malloc é do tipo genérico  void *.   O programador armazena esse endereço num ponteiro de tipo apropriado. No exemplo acima, o endereço é atribuído ao ponteiro ptr que é do tipo ponteiro-para-char.  A transformação do ponteiro genérico em ponteiro-para-char é automática; não é necessário escrever ptr = (char *) malloc (1);.

A fim de alocar espaço para um objeto que precisa de mais que 1 byte, convém usar o operador sizeof, que diz quantos bytes o objeto em questão tem:

typedef struct {
   int dia, mes, ano; 
} data;
data *d;
d = malloc (sizeof (data));
d->dia = 31; d->mes = 12; d->ano = 2016;
Note que sizeof não é uma função mas um operador, tal como return, por exemplo. Os parênteses na expressão sizeof (data) são necessários porque data é um tipo-de-dados  (os parênteses são análogos aos do casting).  O operador sizeof também pode ser aplicado diretamente a uma variável:  se var é uma variável então  sizeof var  é o número de bytes ocupado por var.  Poderíamos ter escrito d = malloc (sizeof *d) no exemplo acima.

Exercícios 1
Escreva uma função que receba um byte c (que pode representar um caractere ASCII, por exemplo) e transforme-o em uma string, ou seja, devolva uma string de comprimento 1 tendo c como único elemento.
Discuta, passo a passo, o efeito do seguinte fragmento de código:
   int *v;
   v = malloc (10 * sizeof (int));
Discuta o efeito do seguinte fragmento de código:
   x = malloc (10 * sizeof *x);
A função free
As variáveis alocadas estaticamente dentro de uma função, também conhecidas como variáveis automáticas ou locais, desaparecem assim que a execução da função termina. Já as variáveis alocadas dinamicamente continuam a existir mesmo depois que a execução da função termina. Se for necessário liberar a memória ocupada por essas variáveis, é preciso recorrer à função free.

A função free desaloca a porção de memória alocada por malloc. A instrução free (ptr) avisa ao sistema que o bloco de bytes apontado por ptr está disponível para reciclagem. A próxima invocação de malloc poderá tomar posse desses bytes.

A função free não deve ser aplicada a uma parte de um bloco de bytes alocado por malloc (ou realloc). Aplique free apenas ao bloco todo.

Exercícios 2
O que há de errado com o seguinte fragmento de código?
   int *v;
   v = malloc (100 * sizeof (int));
   v[0] = 999;
   free (v+1);
A seguinte função promete devolver um vetor com os 3 primeiros números primos maiores que 1000. Onde está o erro?
int *primos (void) {
   int v[3];
   v[0] = 1009; v[1] = 1013; v[2] = 1019;
   return v; }
A seguinte função promete acrescentar uma célula-cabeça à lista encadeada lst e devolver o endereço da nova lista. Onde está o erro?
celula *acrescentaCabeca (celula *lst) {
   celula cabeca;
   cabeca.prox = lst;
   return &cabeca; }
Discuta, passo a passo, o efeito do seguinte fragmento de código:
   int *p, *q;
   p = malloc (sizeof (int));
   *p = 123;
   q = malloc (sizeof (int));
   *q = *p;
   q = p; 
   free (p);
   free (q); // má ideia...
   q = NULL; // boa ideia
Vetores e matrizes
Eis como um vetor (= array) com n elementos inteiros pode ser alocado (e depois desalocado) durante a execução de um programa:

   int *v; 
   int n;
   scanf ("%d", &n);
   v = malloc (n * sizeof (int));
   for (int i = 0; i < n; ++i) 
      scanf ("%d", &v[i]);
   . . . 
   free (v);
(A propósito, veja a observação sobre endereços e vetores no capítulo Endereços e ponteiros.)  Do ponto de vista conceitual, mas apenas desse ponto de vista, a instrução

   v = malloc (100 * sizeof (int));
tem efeito análogo ao da alocação estática

   int v[100];
Matrizes.   Matrizes bidimensionais são implementadas como vetores de vetores. Uma matriz com m linhas e n colunas é um vetor de m elementos cada um dos quais é um vetor de n elementos. O seguinte fragmento de código faz a alocação dinâmica de uma tal matriz:

   int **M; 
   M = malloc (m * sizeof (int *));
   for (int i = 0; i < m; ++i)
      M[i] = malloc (n * sizeof (int));
Portanto, M[i][j] é o elemento de M que está no cruzamento da linha i com a coluna j.

Exercícios 3
Escreva uma função que desaloque a matriz M alocada acima. Quais devem ser os parâmetros da função?
Redimensionamento e a função realloc
Às vezes é necessário alterar, durante a execução do programa, o tamanho de um bloco de bytes que foi alocado por malloc.  Isso acontece, por exemplo, durante a leitura de um arquivo que se revela maior que o esperado.  Nesse caso, podemos recorrer à função realloc para redimensionar o bloco de bytes.

A função realloc recebe o endereço de um bloco previamente alocado por malloc (ou por realloc) e o número de bytes que o bloco redimensionado deve ter. A função aloca o novo bloco, copia para ele o conteúdo do bloco original, e devolve o endereço do novo bloco.

Se o novo bloco for uma extensão do bloco original, seu endereço é o mesmo do original (e o conteúdo do original não precisa ser copiado para o novo). Caso contrário, realloc copia o conteúdo do bloco original para o novo e libera o bloco original (invocando free).  A propósito, o tamanho do novo bloco pode ser menor que o do bloco original.

Suponha, por exemplo, que alocamos um vetor de 1000 inteiros e depois decidimos que precisamos de duas vezes mais espaço. Veja um caso concreto:

   int *v;
   v = malloc (1000 * sizeof (int));
   for (int i = 0; i < 990; i++)
      scanf ("%d", &v[i]);
   v = realloc (v, 2000 * sizeof (int));
   for (int i = 990; i < 2000; i++)
      scanf ("%d", &v[i]);
Nesse exemplo, poderíamos usar a seguinte implementação ad hoc de realloc:

int *realloc (int *v, unsigned int N) {
   int *novo = malloc (N);
   for (int i = 0; i < 1000; i++)
      novo[i] = v[i];
   free (v);
   return novo;
}
É claro que a implementação de realloc na biblioteca stdlib é mais geral e mais eficiente.

Exercícios 4
Suponha dado um arquivo de texto que contém uma sequência de números inteiros. O comprimento da sequência é desconhecido. Escreva uma função que imprima esses números em ordem inversa (o último, depois o penúltimo, etc.).  É claro que você terá que ler todos os números e armazená-los na memória.  A dificuldade está em alocar espaço para uma quantidade de números que só será conhecida quando chegarmos ao fim do arquivo. 
A memória é finita
Se a memória do computador já estiver toda ocupada, malloc não consegue alocar mais espaço e devolve NULL. Convém verificar essa possibilidade antes de prosseguir:

ptr = malloc (sizeof (data));
if (ptr == NULL) {
   printf ("Socorro! malloc devolveu NULL!\n");
   exit (EXIT_FAILURE);
}
A digitação frequente e repetida desse teste é cansativa. Por isso, usaremos, neste sítio, a seguinte função-embalagem (= wrapper function):

void *mallocc (size_t nbytes)
{
   void *ptr;
   ptr = malloc (nbytes);
   if (ptr == NULL) {
      printf ("Socorro! malloc devolveu NULL!\n");
      exit (EXIT_FAILURE);
   }
   return ptr;
}
O parâmetro de mallocc é do tipo  size_t  (abreviatura de size data type); em muitos computadores, size_t é o mesmo que unsigned int.

Da mesma forma, podemos preparar uma função-embalagem reallocc para cuidar das situações em que realloc devolve NULL.

Perguntas e respostas
Pergunta:  É verdade que não convém alocar blocos de poucos bytes, ou seja, invocar malloc com argumento muito pequeno?
Resposta:  Cada invocação de malloc aloca um bloco de bytes maior que o solicitado; os bytes adicionais são usados para guardar informações administrativas sobre o bloco (essas informações permitem que o bloco seja corretamente desalocado, mais tarde, pela função free).  Assim, não é eficiente alocar blocos muito pequenos repetidamente; é melhor alocar um bloco grande e dele retirar pequenas porções na medida do necessário.  A boa notícia é que o programador não precisa fazer isso pessoalmente pois malloc implementa essa política por baixo do pano sem que o programador perceba.

Pergunta:  Posso alocar um vetor estaticamente com número não-constante de elementos?  Por exemplo, posso dizer
int v[n];
se o valor de n só se torna conhecido durante a execução do programa?

Resposta:  Não é uma boa ideia.

Pergunta:  É verdade que devemos atribiuir NULL a cada ponteiro que se tornou inútil ou desnecessário?
Resposta:  Sim. Convém não deixar ponteiros soltos (= dangling pointers) no seu programa, pois isso pode dificultar a depuração do programa e pode ser explorado por hackers para atacar o seu computador. Portanto, depois de cada free (ptr), atribua NULL a ptr:

free (ptr);
ptr = NULL;
(Atribuir um valor a uma variável que não será mais usada é decididamente deselegante, mas não há como lidar com hackers de maneira elegante…)   Para não cansar o leitor com detalhes repetitivos, este sítio ignora essa recomendação de segurança.

Pergunta:  É verdade que deveríamos usar a função calloc no lugar de malloc?
Resposta:  Talvez. A chamada calloc (a, b) aloca um bloco de a*b bytes e atribui valor zero a todos esses bytes. Veja o artigo Why does calloc exist? de Nathaniel J. Smith (2016).

Julia's drawings: Memory allocation

Valgrind: ferramenta para encontrar vazamentos de memória (= memory leaks) e segmentation faults no seu programa

Atualizado em 2018-05-29
https://www.ime.usp.br/~pf/algoritmos/
Paulo Feofiloff
DCC-IME-USP

 Valid CSS!  Valid HTML 4.01 Strict
