Projeto de Algoritmos   |   Linguagem C   |   �ndice

Strings e cadeias de caracteres
[string of numbers and letters]

Este cap�tulo discute o conceito de string na linguagem C. Esse conceito confunde-se �s vezes com o de cadeia de caracteres.  Strings s�o usadas na mem�ria do computador, enquanto cadeias de caracteres aparecem em folhas de papel e na tela do terminal.

Strings
Na linguagem C, uma string � um vetor de bytes em que o byte nulo 00000000 � interpretado como uma sentinela que marca o fim da parte relevante do vetor.  Eis um pequeno exemplo de string:

01000001 01000010 01000011 00000000 01000100
(os s�mbolos 0 e 1 representam bits).  Nesse exemplo, apenas os 4 primeiros bytes constituem a string propriamente dita.

O comprimento (= length) de uma string � o seu n�mero de bytes, sem contar o byte nulo final.  (Assim, a string do exemplo acima tem comprimento 3.)  Uma string � vazia se tem comprimento zero.

Strings e vetores de chars.  Cada byte de uma string � tratado como um char, e portanto uma string � um vetor de chars. Portanto, uma string str pode ser declarada assim:

char *str;
O seguinte exemplo constr�i uma string byte a byte. Depois da execu��o do fragmento de programa

str = malloc (10 * sizeof (char));
str[0] = 65;
str[1] = 66;
str[2] = 67;
str[3] =  0;
str[4] = 68;
o vetor str[0..3] � a string 01000001 01000010 01000011 00000000.  A por��o str[4..9] do vetor � ignorada.

O endere�o de uma string � o endere�o do seu primeiro byte. Em discuss�es informais, � usual confundir uma string com o seu endere�o. Assim, a express�o considere a string str deve ser entendida como considere a string cujo endere�o � str.

Poder�amos tratar strings como um novo tipo-de-dados. Para isso, bastaria introduzir o typedef abaixo e passar a escrever string no lugar de char *.

typedef char *string;
Exerc�cios 1
Escreva uma fun��o que decida se duas strings de mesmo comprimento diferem em exatamente um byte.
Escreva uma fun��o que receba um char c e devolva uma string cujo �nico byte � c.
Vazio versus null.  Suponha que str � uma string.  Qual a difere�a entre as afirma��es str � uma string vazia e str � NULL?
Peda�o de string.  Escreva uma fun��o que receba uma string str e inteiros positivos i e j e devolva uma string com o mesmo conte�do que o segmento str[i..j].  Escreva duas vers�es: na primeira, sua fun��o n�o deve alocar novo espa�o e pode alterar a string str que recebeu; na segunda, sua fun��o deve devolver uma c�pia do segmento str[i..j] e n�o pode alterar a string str que recebeu.
Escreva uma fun��o que receba strings s e t e decida se s � um segmento de t.  Escreva um programa que use a fun��o para contar o n�mero de ocorr�ncias de uma string s em uma string t.
Cadeias de caracteres
Uma cadeia de caracteres � uma sequ�ncias de s�mbolos tipogr�ficos: letras (com ou sem diacr�ticos), d�gitos, sinais de pontua��o, etc.  O texto desta p�gina, por exemplo, � uma longa cadeia de caracteres. Eis um exemplo muito menor de cadeia de caracteres:

ABC
O comprimento de uma cadeia de caracteres � o n�mero de caracteres da cadeia.  A cadeia do exemplo tem comprimento 3.

Strings que representam cadeias de caracteres.  Strings podem ser usadas para representar cadeias de caracteres na mem�ria do computador.  Para definir essa representa��o, � preciso convencionar uma correspond�ncia entre caracteres e bytes. A correspond�ncia mais antiga e mais b�sica � a tabela ASCII, que associa cada caractere do alfabeto ASCII a um byte entre 0 e 127 (esses s�o os bytes cujo primeiro bit � 0).  Por isso, strings cujos bytes pertencem ao intervalo 0..127 s�o chamadas strings ASCII.  Por exemplo, a string  65 66 67 0  (bytes escritos em nota��o decimal) representa a cadeia de caracteres  ABC?.

Caracteres que n�o pertencem ao alfabeto ASCII (como �, �, �, �, etc.) s�o representados por dois ou mais bytes consecutivos. Estamos supondo que nosso ambiente de programa��o usa codifica��o UTF-8; portanto, cada caractere � representado por at� quatro bytes consecutivos e o primeiro byte de cada caractere n�o-ASCII � maior que 127.  (Veja a tabela UTF-8 encoding table and Unicode characters.)  Por exemplo, a string  97 195 167 195 163 111 0  (bytes escritos em nota��o decimal) representa a cadeia de caracteres  a��o.

O c�digo UTF-8 foi constru�do de tal maneira que o caractere \0 (que pertence ao alfabeto ASCII) � o �nico cujo c�digo cont�m um byte nulo. Assim, o primeiro byte nulo da string indica o fim da string bem como o fim da cadeia de caracteres representada.

Exerc�cios 2
[Sedgewick 3.57]  Pal�ndromos.  Escreva uma fun��o que decida se uma string ASCII dada � um pal�ndromo (ou seja, se o inverso da string � igual a ela). Escreva um programa para testar a fun��o.
[Sedgewick 3.56]  ? Escreva uma fun��o que receba uma string ASCII e exiba uma tabela com o n�mero de ocorr�ncias de cada um dos caracteres do alfabeto ASCII na string. Escreva um programa para testar a fun��o.
[Sedgewick 3.60]  ? Escreva uma fun��o que receba uma string ASCII e substitua cada segmento de dois ou mais espa�os por um s� espa�o. Refa�a o exerc�cio depois de remover a restri��o a strings ASCII.
[Sedgewick 3.62]  ? Escreva uma fun��o que calcule o comprimento do mais longo segmento de espa�os em uma string ASCII. Procure examinar o menor n�mero poss�vel de elementos da string. Escreva um programa para testar sua fun��o.
Escreva uma fun��o que decida se uma dada string � ASCII ou n�o.  Suponha codifica��o UTF-8.
? N�mero de caracteres.  Escreva uma fun��o que receba uma string e calcule o comprimento da cadeia de caracteres que a string representa em c�digo UTF-8.  (Dica: Estude a estrutura do c�digo UTF-8.)  [Solu��o]
Leitura e escrita de cadeias
Para obter a cadeia de caracteres que uma string representa, � preciso decodificar a string.  No caso de strings ASCII, a decodifica��o � simples (basta consultar a tabela ASCII). Em geral, entretanto, a decodifica��o � mais complexa.  Felizmente, a fun��o printf com a especifica��o de formato  %s  cuida da decodifica��o.  Por exemplo, o fragmento de programa

char str[100] = {97,195,167,195,163,111,0};
printf ("%s\n", str);
exibe a cadeia de caracteres

a��o
Uma alternativa a printf � a fun��o fputs (o nome � uma abreviatura de file put string) da biblioteca stdio. Essa fun��o grava uma string num arquivo. Por exemplo,

fputs (str, arquivo);
Se o segundo argumento for stdout, a string str � convertida em uma cadeia de caracteres ao ser exibida na tela do terminal.

Leitura.  A especifica��o de formato  %s  tamb�m pode ser usada com a fun��o de leitura scanf. Por exemplo, o c�digo abaixo l� uma cadeia de caracteres do teclado, converte a cadeia numa string (acrescentando um byte nulo ao final) e armazena a string no vetor str:

char str[100];
scanf ("%s", str); 
A fun��o scanf interrompe a leitura ao encontrar o primeiro caractere branco (espa�o, tabula��o, fim de linha, etc.).  Para ler uma cadeia de caracteres que cont�m brancos, use a fun��o fgets (o nome � uma abreviatura de file get string) da biblioteca stdio.  Se o �ltimo argumento de fgets for stdin, a fun��o l� uma cadeia de caracteres do teclado at� o fim da linha (tecla ?), converte a cadeia numa string e armazena-a no endere�o indicado pelo primeiro agumento:

char str[100];
fgets (str, 100, stdin); 
O segundo argumento de fgets � uma prote��o contra linhas muito longas, mais longas que o espa�o reservado para a string. No exemplo acima, se o comprimento da string for maior que 99, somente os 99 primeiros bytes ser�o armazenados em str.  (O n�mero de caracteres lidos pode ser menor que 99 se algum dos caracteres for representado por dois ou mais bytes.)

Cadeias constantes
Para especificar uma cadeia de caracteres constante, basta embrulhar a cadeia de caracteres num par de aspas duplas retas. Quando um tal cadeia constante � atribu�da a uma string, ela � convertida numa sequ�ncia de bytes e um byte nulo � acrescentado ao final. Por exemplo,

char *str;
str = "ABC";
produz efeito semelhante ao que aparece num dos exemplos acima.  Os caracteres de uma cadeia constante n�o precisam pertencer ao alfabeto ASCII.  Podemos dizer, por exemplo,

str = "a��o";
Nesse caso, supondo codifica��o UTF-8, a string str ter� 7 bytes: o primeiro e o �ltimo caracteres ocupam 1 byte cada, os dois caracteres do meio ocupam 2 bytes cada, e h� um byte nulo no fim.

Cadeias constantes de caracteres aparecem com frequ�ncia em programas C.  Basta lembrar o primeiro argumento das fun��es printf e scanf.

Exemplo: contagem de vogais.  A seguinte fun��o conta o n�mero de vogais em uma string ASCII:

int contaVogais (char s[]) {
   char *vogais;
   vogais = "aeiouAEIOU";
   int numVogais = 0;
   for (int i = 0; s[i] != '\0'; ++i) {
      char ch = s[i];
      for (int j = 0; vogais[j] != '\0'; ++j) {
         if (vogais[j] == ch) {
            numVogais += 1;
            break;
         }
      }
   }
   return numVogais;
}
Exerc�cios 4
Qual o efeito do seguinte fragmento de programa?
char *s;
s = "ABC";
printf ("%s\n", s);
O que h� de errado com a seguinte variante do exerc�cio anterior?
char s[20];
s = "ABC";
printf ("%s\n", s);
Qual a diferen�a entre "A" e 'A'?
Qual a diferen�a entre "mno" e "m\no"?  Qual a diferen�a entre "MNOP" e "MN0P"?  Qual a diferen�a entre "MN\0P" e "MN0P"?
Reescreva a fun��o contaVogais depois de remover a restri��o a strings ASCII. Suponha que a string representa um texto em portugu�s e conte �, �, �, etc. como vogais.
Remove acentos.  ? Escreva uma fun��o que remova todos os sinais diacr�ticos de uma cadeia de caracteres dada, trocando � por A, � por a, � por c, e assim por diante.  A cadeia de caracteres dada � representada por uma string em c�digo UTF-8, mas voc� pode supor que apenas os caracteres com sinais diacr�ticos usados em portugu�s aparecem na cadeia. A nova cadeia de caracteres deve ser representada por uma string ASCII.
Escreva um programa para converter nota��o decimal em nota��o hexadecimal.  O seu programa deve receber, pela linha de comando, um n�mero em nota��o decimal e exibir a representa��o hexadecimal do n�mero.  Repita o exerc�cio para converter hexadecimal em decimal, decimal em octal, octal em decimal, etc.
Inteiro para string decimal.  Escreva uma fun��o que receba um inteiro n e devolva a string ASCII de d�gitos decimais que represente n da maneira usual. Por exemplo, o inteiro -123 deve ser convertido em "-123".
String decimal para inteiro.  Escreva uma fun��o que receba uma string ASCII de d�gitos decimais e devolva o correspondente n�mero inteiro positivo. Por exemplo, ao receber a string "123", devolve o inteiro 123.  (Se a string for longa demais, descarte os �ltimos d�gitos.)  Depois, fa�a uma vers�o mais sofisticada da fun��o que permita que o primeiro elemento da string seja '+' ou '-'.
Inteiro para string bin�ria.  Escreva uma fun��o que receba um inteiro positivo n e devolva a string ASCII de 0s e 1s que represente n em nota��o bin�ria. Por exemplo, o inteiro 123 deve ser convertido em "1111011".
String bin�ria para inteiro.  Escreva uma fun��o que receba uma string ASCII de 0s e 1s, interprete essa string como um n�mero natural em nota��o bin�ria e devolva o valor desse n�mero. (Se a string for longa demais, descarte os �ltimos d�gitos.) Por exemplo, a string "1111011" deve ser convertida no inteiro 123.
Ordem lexicogr�fica
A ordem lexicogr�fica entre strings (erroneamente conhecida como ordem alfab�tica) � an�loga � ordem em que as palavras constam de um dicion�rio:  uma string s precede uma string t se o primeiro byte de s diferente do correspondente byte de t � menor que o byte de t.  Dizemos tamb�m que s � lexicograficamente menor que t.

Portanto, para comparar lexicograficamente duas strings s e t fa�a o seguinte. Procure a primeira posi��o, digamos k, em que as duas strings diferem. Se s[k] < t[k] ent�o s � lexicograficamente menor que t.  Se s[k] > t[k] ent�o s � lexicograficamente maior que t.  Se k n�o est� definido ent�o s e t s�o iguais ou uma � prefixo pr�prio da outra; no segundo caso, a string mais curta � lexicograficamente menor que a mais longa.

Exerc�cios 6
Escreva uma fun��o que receba duas strings digamos s e t, e decida se s � lexicograficamente menor que t.
O seguinte fragmento de programa pretende decidir se abacate vem antes ou depois de banana no dicion�rio. O que h� de errado?
char *b, *a;
a = "abacate"; b = "banana";
if (a < b) printf ("%s vem antes de %s\n", a, b);
else       printf ("%s vem depois de %s\n", a, b);
O seguinte fragmento de programa pretende decidir se abacate vem antes ou depois de amora no dicion�rio. O que h� de errado?
char *a, *b;
a = "abacate"; b = "amora";
if (*a < *b) printf ("%s vem antes de %s\n", a, b);
else         printf ("%s vem depois de %s\n", a, b);
A biblioteca string
A biblioteca string (n�o confunda com a biblioteca obsoleta strings) cont�m v�rias fun��es de manipula��o de strings.  Para usar essas fun��es, o seu programa deve incluir a interface string.h:

#include <string.h>
Segue uma descri��o das fun��es mais importantes da biblioteca.

String length.  A fun��o strlen recebe uma string e devolve o seu comprimento.  O c�digo dessa fun��o poderia ser escrito assim:

unsigned int strlen (char *s) {
   int k;
   for (k = 0; s[k] != '\0'; ++k) ;
   return k;
}
String copy.  A fun��o strcpy recebe duas strings e copia a segunda (inclusive o byte nulo final) para o espa�o ocupado pela primeira. O conte�do original da primeira string � perdido. N�o chame a fun��o se o comprimento da primeira string for menor que o da segunda.  (Buffer overflow � uma das mais comuns origens de bugs de seguran�a!)  O c�digo dessa fun��o poderia ser escrito assim:

void strcpy (char *s, char *t) {
   int i;
   for (i = 0; t[i] != '\0'; ++i) 
      s[i] = t[i];
   s[i] = '\0';
}
(Na verdade, a fun��o strcpy n�o � do tipo void;  ela � do tipo char* e devolve o seu primeiro argumento. Isso � �til em algumas situa��es, mas em geral o usu�rio s� est� interessado no efeito da fun��o e n�o no que ela devolve.)

A fun��o strcpy pode ser usada da seguinte maneira para obter um efeito semelhante ao do exemplo no in�cio deste cap�tulo:

char s[10];
strcpy (s, "ABC");
String compare.  A fun��o strcmp recebe duas strings e compara as duas lexicograficamente. Ela devolve um n�mero estritamente negativo se a primeira string for lexicograficamente menor que a segunda, devolve 0 se as duas strings s�o iguais e devolve um n�mero estritamente positivo se a primeira string for lexicograficamente maior que a segunda.  O c�digo da fun��o poderia ser escrito assim:

int strcmp (char *s, char *t) {
   int i;
   for (i = 0; s[i] == t[i]; ++i)
      if (s[i] == '\0') return 0;
   unsigned char si = s[i], ti = t[i];
   return si - ti;
}
(Vale lembrar que o valor da express�o  si - ti  � calculado em aritm�tica int, e n�o m�dulo 256.)

Se as strings s e t s�o ASCII, elas representam cadeias de caracteres ASCII. Nesse caso, a ordem lexicogr�fica entre as strings coincide com a ordem em que as cadeias apareceriam em um dicion�rio (pois a ordem  � 0 � 9 � A B � Z � a b � z �  em que os caracteres aparecem na tabela ASCII � consistente com a ordem alfab�tica usual). Por exemplo, a seguinte sequ�ncia de palavras est� em ordem lexicogr�fica:

abacaXi
abacate
abacates
abacaxi
Se as strings n�o s�o ASCII (ou seja, se t�m bytes maiores que 127), a situa��o � potencialmente mais complexa. Nesse caso, cada string representa uma cadeia de caracteres em c�digo UTF-8, e portanto cada caractere � representado por 1 a 4 bytes consecutivos. Felizmente, o c�digo UTF-8 foi constru�do de tal maneira que ? a ordem lexicogr�fica entre as strings coincide com a ordem em que as cadeias apareceriam em um dicion�rio se os caracteres fossem colocados em ordem crescente dos seus n�meros Unicode, ou seja, � 0 � 9 � A B � Z � a b � z � � � � � � � � � � � � �  (veja a sequ�ncia completa na p�gina UTF-8 encoding table and Unicode characters, por exemplo). Por exemplo, a seguinte sequ�ncia de palavras est� em ordem lexicogr�fica:

abocanhar
abrir
ab�bora
academia
acordar
ac�cia
adaptar
a�o
a�ucarado
a��o
(Essa ordem lexicogr�fica parece estranha pois deixa as letras acentuadas longe das correspondentes letras sem acentos. A prop�sito, veja a fun��o strcoll num dos exerc�cio abaixo.)

Exerc�cios 7
Qual a diferen�a entre as express�es  strcpy (s, t)  e  s = t??
Qual a diferen�a entre as express�es  if (strcmp (s, t) < 0)  e  if (s < t)??
Discuta as diferen�as entre os tr�s fragmentos de programa a seguir:
char a[8], b[8];
strcpy (a, "abacate"); strcpy (b, "banana");
char *a = malloc (8), *b = malloc (8); 
strcpy (a, "abacate"); strcpy (b, "banana");
char *a, *b; 
a = "abacate"; b = "banana";
Estude a documenta��o da fun��o strncpy da biblioteca string.
Escreva uma fun��o que receba uma string s e devolva uma c�pia de s.  (Compare sua fun��o com a fun��o strdup da biblioteca string. Qual a diferen�a entre essa fun��o e strcpy?)
Escreva uma fun��o que receba uma string ASCII s e um caractere ASCII c e devolva o �ndice da primeira posi��o em s que � igual a c.  (Compare sua fun��o com a fun��o strchr da biblioteca string.  Agora fa�a uma vers�o mais completa da fun��o para procurar c a partir de uma dada posi��o i.
Escreva uma fun��o que receba strings x e s e devolva o �ndice da posi��o a partir da qual x ocorre em s.  (Compare sua fun��o com a fun��o strstr da biblioteca string.)
Escreva uma fun��o que decida se um vetor vs[0..n-1] de strings est� em ordem lexicogr�fica.
? Suponha dado um vetor vs[0..n-1] de strings, em ordem lexicogr�fica, e uma string s.  Problema: se vs n�o cont�m uma string igual a s, inserir s no vetor de modo a manter a ordem lexicogr�fica. Escreva uma fun��o que resolva o problema e devolva 1 se a inser��o tiver sido feita e 0 em caso contr�rio.
? Suponha que strings s e t representam, em c�digo UTF-8, as cadeias de caracteres S e T respectivamente. Prove que a ordem lexicogr�fica entre s e t (dada por strcmp (s, t)) coincide com a ordem em que as cadeias S e T estariam num dicion�rio se o conjunto de caracteres estivesse em ordem crescente de n�meros Unicode.
? Ordem lexicogr�fica em portugu�s.  A ordem lexicogr�fica calculada pela fun��o strcmp compara duas strings byte a byte, ignorando as caracter�sticas do eventual esquema de codifica��o. Se as strings representam cadeias de caracteres em c�digo UTF-8, a ordem lexicogr�fica � consistente com a ordem crescente dos n�meros Unicode dos caracteres. Infelizmente, essa n�o � a ordem usual de um dicion�rio de portugu�s, pois as letras mai�sculas ficam longe das correspondentes min�sculas e longe das correspondentes letras com diacr�ticos (por exemplo, A, a e � ficam longe umas das outras). Para contornar esse inconveniente, use a variante strcoll de strcmp. ? A ordem lexicogr�fica calculada por strcoll (o nome da fun��o � uma abreviatura de string collate) usa a ordena��o dos caracteres determinada pela vari�vel de ambiente LC_COLLATE do seu sistema. Se o valor de LC_COLLATE � pt_BR.UTF-8, por exemplo, a ordem dos caracteres �  � a A � � � � � � � b B c C � � d D � z Z �
Use a fun��o strcoll para escrever um programa que ordene lexicograficamente uma sequ�ncia de palavras em portugu�s codificada em UTF-8. As palavras s�o digitadas no terminal e a lista ordenada deve ser exibida na tela, uma por linha. Fa�a testes. Se o valor de LC_COLLATE no seu sistema n�o for pt_BR.UTF-8, voc� pode fazer algo assim:

#include <locale.h>
void main (void) {
   setlocale (LC_COLLATE, "pt_BR.UTF-8");
   ... c�digo da ordena��o ...
}
Veja a biblioteca strlib de Eric Roberts
Veja os verbetes C string handling e Null-terminated string na Wikipedia
Veja o artigo On Character Strings de Tim Bray
Atualizado em 2018-05-09
https://www.ime.usp.br/~pf/algoritmos/
Paulo Feofiloff
DCC-IME-USP

 Valid CSS!  Valid HTML 4.01 Strict
