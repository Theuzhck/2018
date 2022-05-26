Projeto de Algoritmos   |   Linguagem C   |   �ndice

Aloca��o din�mica de mem�ria
As declara��es abaixo alocam espa�o de mem�ria para diversas vari�veis. A aloca��o � est�tica (nada a ver com a palavra-chave static), ou seja, acontece antes que o programa comece a ser executado:

char c; 
int i; 
int v[10]; 
Em muitas aplica��es, a quantidade de mem�ria a alocar s� se torna conhecida durante a execu��o do programa. Para lidar com essa situa��o � preciso recorrer � aloca��o din�mica de mem�ria. A aloca��o din�mica � administrada pelas fun��es malloc, realloc e free, que est�o na biblioteca stdlib.  Para usar essa biblioteca, inclua a correspondente interface no seu programa:

#include <stdlib.h>
A fun��o malloc
A fun��o  malloc  (o nome � uma abreviatura de memory allocation) aloca espa�o para um bloco de bytes consecutivos na mem�ria RAM (= random access memory) do computador e devolve o endere�o desse bloco.  O n�mero de bytes � especificado no argumento da fun��o. No seguinte fragmento de c�digo, malloc aloca 1 byte:

char *ptr;
ptr = malloc (1);
scanf ("%c", ptr);
O endere�o devolvido por malloc � do tipo gen�rico  void *.   O programador armazena esse endere�o num ponteiro de tipo apropriado. No exemplo acima, o endere�o � atribu�do ao ponteiro ptr que � do tipo ponteiro-para-char.  A transforma��o do ponteiro gen�rico em ponteiro-para-char � autom�tica; n�o � necess�rio escrever ptr = (char *) malloc (1);.

A fim de alocar espa�o para um objeto que precisa de mais que 1 byte, conv�m usar o operador sizeof, que diz quantos bytes o objeto em quest�o tem:

typedef struct {
   int dia, mes, ano; 
} data;
data *d;
d = malloc (sizeof (data));
d->dia = 31; d->mes = 12; d->ano = 2016;
Note que sizeof n�o � uma fun��o mas um operador, tal como return, por exemplo. Os par�nteses na express�o sizeof (data) s�o necess�rios porque data � um tipo-de-dados  (os par�nteses s�o an�logos aos do casting).  O operador sizeof tamb�m pode ser aplicado diretamente a uma vari�vel:  se var � uma vari�vel ent�o  sizeof var  � o n�mero de bytes ocupado por var.  Poder�amos ter escrito d = malloc (sizeof *d) no exemplo acima.

Exerc�cios 1
Escreva uma fun��o que receba um byte c (que pode representar um caractere ASCII, por exemplo) e transforme-o em uma string, ou seja, devolva uma string de comprimento 1 tendo c como �nico elemento.
Discuta, passo a passo, o efeito do seguinte fragmento de c�digo:
   int *v;
   v = malloc (10 * sizeof (int));
Discuta o efeito do seguinte fragmento de c�digo:
   x = malloc (10 * sizeof *x);
A fun��o free
As vari�veis alocadas estaticamente dentro de uma fun��o, tamb�m conhecidas como vari�veis autom�ticas ou locais, desaparecem assim que a execu��o da fun��o termina. J� as vari�veis alocadas dinamicamente continuam a existir mesmo depois que a execu��o da fun��o termina. Se for necess�rio liberar a mem�ria ocupada por essas vari�veis, � preciso recorrer � fun��o free.

A fun��o free desaloca a por��o de mem�ria alocada por malloc. A instru��o free (ptr) avisa ao sistema que o bloco de bytes apontado por ptr est� dispon�vel para reciclagem. A pr�xima invoca��o de malloc poder� tomar posse desses bytes.

A fun��o free n�o deve ser aplicada a uma parte de um bloco de bytes alocado por malloc (ou realloc). Aplique free apenas ao bloco todo.

Exerc�cios 2
O que h� de errado com o seguinte fragmento de c�digo?
   int *v;
   v = malloc (100 * sizeof (int));
   v[0] = 999;
   free (v+1);
A seguinte fun��o promete devolver um vetor com os 3 primeiros n�meros primos maiores que 1000. Onde est� o erro?
int *primos (void) {
   int v[3];
   v[0] = 1009; v[1] = 1013; v[2] = 1019;
   return v; }
A seguinte fun��o promete acrescentar uma c�lula-cabe�a � lista encadeada lst e devolver o endere�o da nova lista. Onde est� o erro?
celula *acrescentaCabeca (celula *lst) {
   celula cabeca;
   cabeca.prox = lst;
   return &cabeca; }
Discuta, passo a passo, o efeito do seguinte fragmento de c�digo:
   int *p, *q;
   p = malloc (sizeof (int));
   *p = 123;
   q = malloc (sizeof (int));
   *q = *p;
   q = p; 
   free (p);
   free (q); // m� ideia...
   q = NULL; // boa ideia
Vetores e matrizes
Eis como um vetor (= array) com n elementos inteiros pode ser alocado (e depois desalocado) durante a execu��o de um programa:

   int *v; 
   int n;
   scanf ("%d", &n);
   v = malloc (n * sizeof (int));
   for (int i = 0; i < n; ++i) 
      scanf ("%d", &v[i]);
   . . . 
   free (v);
(A prop�sito, veja a observa��o sobre endere�os e vetores no cap�tulo Endere�os e ponteiros.)  Do ponto de vista conceitual, mas apenas desse ponto de vista, a instru��o

   v = malloc (100 * sizeof (int));
tem efeito an�logo ao da aloca��o est�tica

   int v[100];
Matrizes.   Matrizes bidimensionais s�o implementadas como vetores de vetores. Uma matriz com m linhas e n colunas � um vetor de m elementos cada um dos quais � um vetor de n elementos. O seguinte fragmento de c�digo faz a aloca��o din�mica de uma tal matriz:

   int **M; 
   M = malloc (m * sizeof (int *));
   for (int i = 0; i < m; ++i)
      M[i] = malloc (n * sizeof (int));
Portanto, M[i][j] � o elemento de M que est� no cruzamento da linha i com a coluna j.

Exerc�cios 3
Escreva uma fun��o que desaloque a matriz M alocada acima. Quais devem ser os par�metros da fun��o?
Redimensionamento e a fun��o realloc
�s vezes � necess�rio alterar, durante a execu��o do programa, o tamanho de um bloco de bytes que foi alocado por malloc.  Isso acontece, por exemplo, durante a leitura de um arquivo que se revela maior que o esperado.  Nesse caso, podemos recorrer � fun��o realloc para redimensionar o bloco de bytes.

A fun��o realloc recebe o endere�o de um bloco previamente alocado por malloc (ou por realloc) e o n�mero de bytes que o bloco redimensionado deve ter. A fun��o aloca o novo bloco, copia para ele o conte�do do bloco original, e devolve o endere�o do novo bloco.

Se o novo bloco for uma extens�o do bloco original, seu endere�o � o mesmo do original (e o conte�do do original n�o precisa ser copiado para o novo). Caso contr�rio, realloc copia o conte�do do bloco original para o novo e libera o bloco original (invocando free).  A prop�sito, o tamanho do novo bloco pode ser menor que o do bloco original.

Suponha, por exemplo, que alocamos um vetor de 1000 inteiros e depois decidimos que precisamos de duas vezes mais espa�o. Veja um caso concreto:

   int *v;
   v = malloc (1000 * sizeof (int));
   for (int i = 0; i < 990; i++)
      scanf ("%d", &v[i]);
   v = realloc (v, 2000 * sizeof (int));
   for (int i = 990; i < 2000; i++)
      scanf ("%d", &v[i]);
Nesse exemplo, poder�amos usar a seguinte implementa��o ad hoc de realloc:

int *realloc (int *v, unsigned int N) {
   int *novo = malloc (N);
   for (int i = 0; i < 1000; i++)
      novo[i] = v[i];
   free (v);
   return novo;
}
� claro que a implementa��o de realloc na biblioteca stdlib � mais geral e mais eficiente.

Exerc�cios 4
Suponha dado um arquivo de texto que cont�m uma sequ�ncia de n�meros inteiros. O comprimento da sequ�ncia � desconhecido. Escreva uma fun��o que imprima esses n�meros em ordem inversa (o �ltimo, depois o pen�ltimo, etc.).  � claro que voc� ter� que ler todos os n�meros e armazen�-los na mem�ria.  A dificuldade est� em alocar espa�o para uma quantidade de n�meros que s� ser� conhecida quando chegarmos ao fim do arquivo. 
A mem�ria � finita
Se a mem�ria do computador j� estiver toda ocupada, malloc n�o consegue alocar mais espa�o e devolve NULL. Conv�m verificar essa possibilidade antes de prosseguir:

ptr = malloc (sizeof (data));
if (ptr == NULL) {
   printf ("Socorro! malloc devolveu NULL!\n");
   exit (EXIT_FAILURE);
}
A digita��o frequente e repetida desse teste � cansativa. Por isso, usaremos, neste s�tio, a seguinte fun��o-embalagem (= wrapper function):

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
O par�metro de mallocc � do tipo  size_t  (abreviatura de size data type); em muitos computadores, size_t � o mesmo que unsigned int.

Da mesma forma, podemos preparar uma fun��o-embalagem reallocc para cuidar das situa��es em que realloc devolve NULL.

Perguntas e respostas
Pergunta:  � verdade que n�o conv�m alocar blocos de poucos bytes, ou seja, invocar malloc com argumento muito pequeno?
Resposta:  Cada invoca��o de malloc aloca um bloco de bytes maior que o solicitado; os bytes adicionais s�o usados para guardar informa��es administrativas sobre o bloco (essas informa��es permitem que o bloco seja corretamente desalocado, mais tarde, pela fun��o free).  Assim, n�o � eficiente alocar blocos muito pequenos repetidamente; � melhor alocar um bloco grande e dele retirar pequenas por��es na medida do necess�rio.  A boa not�cia � que o programador n�o precisa fazer isso pessoalmente pois malloc implementa essa pol�tica por baixo do pano sem que o programador perceba.

Pergunta:  Posso alocar um vetor estaticamente com n�mero n�o-constante de elementos?  Por exemplo, posso dizer
int v[n];
se o valor de n s� se torna conhecido durante a execu��o do programa?

Resposta:  N�o � uma boa ideia.

Pergunta:  � verdade que devemos atribiuir NULL a cada ponteiro que se tornou in�til ou desnecess�rio?
Resposta:  Sim. Conv�m n�o deixar ponteiros soltos (= dangling pointers) no seu programa, pois isso pode dificultar a depura��o do programa e pode ser explorado por hackers para atacar o seu computador. Portanto, depois de cada free (ptr), atribua NULL a ptr:

free (ptr);
ptr = NULL;
(Atribuir um valor a uma vari�vel que n�o ser� mais usada � decididamente deselegante, mas n�o h� como lidar com hackers de maneira elegante�)   Para n�o cansar o leitor com detalhes repetitivos, este s�tio ignora essa recomenda��o de seguran�a.

Pergunta:  � verdade que dever�amos usar a fun��o calloc no lugar de malloc?
Resposta:  Talvez. A chamada calloc (a, b) aloca um bloco de a*b bytes e atribui valor zero a todos esses bytes. Veja o artigo Why does calloc exist? de Nathaniel J. Smith (2016).

Julia's drawings: Memory allocation

Valgrind: ferramenta para encontrar vazamentos de mem�ria (= memory leaks) e segmentation faults no seu programa

Atualizado em 2018-05-29
https://www.ime.usp.br/~pf/algoritmos/
Paulo Feofiloff
DCC-IME-USP

 Valid CSS!  Valid HTML 4.01 Strict
