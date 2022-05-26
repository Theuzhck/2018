Projeto de Algoritmos   |   Linguagem C   |   Índice

Strings e cadeias de caracteres
[string of numbers and letters]

Este capítulo discute o conceito de string na linguagem C. Esse conceito confunde-se às vezes com o de cadeia de caracteres.  Strings são usadas na memória do computador, enquanto cadeias de caracteres aparecem em folhas de papel e na tela do terminal.

Strings
Na linguagem C, uma string é um vetor de bytes em que o byte nulo 00000000 é interpretado como uma sentinela que marca o fim da parte relevante do vetor.  Eis um pequeno exemplo de string:

01000001 01000010 01000011 00000000 01000100
(os símbolos 0 e 1 representam bits).  Nesse exemplo, apenas os 4 primeiros bytes constituem a string propriamente dita.

O comprimento (= length) de uma string é o seu número de bytes, sem contar o byte nulo final.  (Assim, a string do exemplo acima tem comprimento 3.)  Uma string é vazia se tem comprimento zero.

Strings e vetores de chars.  Cada byte de uma string é tratado como um char, e portanto uma string é um vetor de chars. Portanto, uma string str pode ser declarada assim:

char *str;
O seguinte exemplo constrói uma string byte a byte. Depois da execução do fragmento de programa

str = malloc (10 * sizeof (char));
str[0] = 65;
str[1] = 66;
str[2] = 67;
str[3] =  0;
str[4] = 68;
o vetor str[0..3] é a string 01000001 01000010 01000011 00000000.  A porção str[4..9] do vetor é ignorada.

O endereço de uma string é o endereço do seu primeiro byte. Em discussões informais, é usual confundir uma string com o seu endereço. Assim, a expressão considere a string str deve ser entendida como considere a string cujo endereço é str.

Poderíamos tratar strings como um novo tipo-de-dados. Para isso, bastaria introduzir o typedef abaixo e passar a escrever string no lugar de char *.

typedef char *string;
Exercícios 1
Escreva uma função que decida se duas strings de mesmo comprimento diferem em exatamente um byte.
Escreva uma função que receba um char c e devolva uma string cujo único byte é c.
Vazio versus null.  Suponha que str é uma string.  Qual a difereça entre as afirmações str é uma string vazia e str é NULL?
Pedaço de string.  Escreva uma função que receba uma string str e inteiros positivos i e j e devolva uma string com o mesmo conteúdo que o segmento str[i..j].  Escreva duas versões: na primeira, sua função não deve alocar novo espaço e pode alterar a string str que recebeu; na segunda, sua função deve devolver uma cópia do segmento str[i..j] e não pode alterar a string str que recebeu.
Escreva uma função que receba strings s e t e decida se s é um segmento de t.  Escreva um programa que use a função para contar o número de ocorrências de uma string s em uma string t.
Cadeias de caracteres
Uma cadeia de caracteres é uma sequências de símbolos tipográficos: letras (com ou sem diacríticos), dígitos, sinais de pontuação, etc.  O texto desta página, por exemplo, é uma longa cadeia de caracteres. Eis um exemplo muito menor de cadeia de caracteres:

ABC
O comprimento de uma cadeia de caracteres é o número de caracteres da cadeia.  A cadeia do exemplo tem comprimento 3.

Strings que representam cadeias de caracteres.  Strings podem ser usadas para representar cadeias de caracteres na memória do computador.  Para definir essa representação, é preciso convencionar uma correspondência entre caracteres e bytes. A correspondência mais antiga e mais básica é a tabela ASCII, que associa cada caractere do alfabeto ASCII a um byte entre 0 e 127 (esses são os bytes cujo primeiro bit é 0).  Por isso, strings cujos bytes pertencem ao intervalo 0..127 são chamadas strings ASCII.  Por exemplo, a string  65 66 67 0  (bytes escritos em notação decimal) representa a cadeia de caracteres  ABC?.

Caracteres que não pertencem ao alfabeto ASCII (como á, ã, é, ç, etc.) são representados por dois ou mais bytes consecutivos. Estamos supondo que nosso ambiente de programação usa codificação UTF-8; portanto, cada caractere é representado por até quatro bytes consecutivos e o primeiro byte de cada caractere não-ASCII é maior que 127.  (Veja a tabela UTF-8 encoding table and Unicode characters.)  Por exemplo, a string  97 195 167 195 163 111 0  (bytes escritos em notação decimal) representa a cadeia de caracteres  ação.

O código UTF-8 foi construído de tal maneira que o caractere \0 (que pertence ao alfabeto ASCII) é o único cujo código contém um byte nulo. Assim, o primeiro byte nulo da string indica o fim da string bem como o fim da cadeia de caracteres representada.

Exercícios 2
[Sedgewick 3.57]  Palíndromos.  Escreva uma função que decida se uma string ASCII dada é um palíndromo (ou seja, se o inverso da string é igual a ela). Escreva um programa para testar a função.
[Sedgewick 3.56]  ? Escreva uma função que receba uma string ASCII e exiba uma tabela com o número de ocorrências de cada um dos caracteres do alfabeto ASCII na string. Escreva um programa para testar a função.
[Sedgewick 3.60]  ? Escreva uma função que receba uma string ASCII e substitua cada segmento de dois ou mais espaços por um só espaço. Refaça o exercício depois de remover a restrição a strings ASCII.
[Sedgewick 3.62]  ? Escreva uma função que calcule o comprimento do mais longo segmento de espaços em uma string ASCII. Procure examinar o menor número possível de elementos da string. Escreva um programa para testar sua função.
Escreva uma função que decida se uma dada string é ASCII ou não.  Suponha codificação UTF-8.
? Número de caracteres.  Escreva uma função que receba uma string e calcule o comprimento da cadeia de caracteres que a string representa em código UTF-8.  (Dica: Estude a estrutura do código UTF-8.)  [Solução]
Leitura e escrita de cadeias
Para obter a cadeia de caracteres que uma string representa, é preciso decodificar a string.  No caso de strings ASCII, a decodificação é simples (basta consultar a tabela ASCII). Em geral, entretanto, a decodificação é mais complexa.  Felizmente, a função printf com a especificação de formato  %s  cuida da decodificação.  Por exemplo, o fragmento de programa

char str[100] = {97,195,167,195,163,111,0};
printf ("%s\n", str);
exibe a cadeia de caracteres

ação
Uma alternativa a printf é a função fputs (o nome é uma abreviatura de file put string) da biblioteca stdio. Essa função grava uma string num arquivo. Por exemplo,

fputs (str, arquivo);
Se o segundo argumento for stdout, a string str é convertida em uma cadeia de caracteres ao ser exibida na tela do terminal.

Leitura.  A especificação de formato  %s  também pode ser usada com a função de leitura scanf. Por exemplo, o código abaixo lê uma cadeia de caracteres do teclado, converte a cadeia numa string (acrescentando um byte nulo ao final) e armazena a string no vetor str:

char str[100];
scanf ("%s", str); 
A função scanf interrompe a leitura ao encontrar o primeiro caractere branco (espaço, tabulação, fim de linha, etc.).  Para ler uma cadeia de caracteres que contém brancos, use a função fgets (o nome é uma abreviatura de file get string) da biblioteca stdio.  Se o último argumento de fgets for stdin, a função lê uma cadeia de caracteres do teclado até o fim da linha (tecla ?), converte a cadeia numa string e armazena-a no endereço indicado pelo primeiro agumento:

char str[100];
fgets (str, 100, stdin); 
O segundo argumento de fgets é uma proteção contra linhas muito longas, mais longas que o espaço reservado para a string. No exemplo acima, se o comprimento da string for maior que 99, somente os 99 primeiros bytes serão armazenados em str.  (O número de caracteres lidos pode ser menor que 99 se algum dos caracteres for representado por dois ou mais bytes.)

Cadeias constantes
Para especificar uma cadeia de caracteres constante, basta embrulhar a cadeia de caracteres num par de aspas duplas retas. Quando um tal cadeia constante é atribuída a uma string, ela é convertida numa sequência de bytes e um byte nulo é acrescentado ao final. Por exemplo,

char *str;
str = "ABC";
produz efeito semelhante ao que aparece num dos exemplos acima.  Os caracteres de uma cadeia constante não precisam pertencer ao alfabeto ASCII.  Podemos dizer, por exemplo,

str = "ação";
Nesse caso, supondo codificação UTF-8, a string str terá 7 bytes: o primeiro e o último caracteres ocupam 1 byte cada, os dois caracteres do meio ocupam 2 bytes cada, e há um byte nulo no fim.

Cadeias constantes de caracteres aparecem com frequência em programas C.  Basta lembrar o primeiro argumento das funções printf e scanf.

Exemplo: contagem de vogais.  A seguinte função conta o número de vogais em uma string ASCII:

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
Exercícios 4
Qual o efeito do seguinte fragmento de programa?
char *s;
s = "ABC";
printf ("%s\n", s);
O que há de errado com a seguinte variante do exercício anterior?
char s[20];
s = "ABC";
printf ("%s\n", s);
Qual a diferença entre "A" e 'A'?
Qual a diferença entre "mno" e "m\no"?  Qual a diferença entre "MNOP" e "MN0P"?  Qual a diferença entre "MN\0P" e "MN0P"?
Reescreva a função contaVogais depois de remover a restrição a strings ASCII. Suponha que a string representa um texto em português e conte á, ã, É, etc. como vogais.
Remove acentos.  ? Escreva uma função que remova todos os sinais diacríticos de uma cadeia de caracteres dada, trocando Á por A, ã por a, ç por c, e assim por diante.  A cadeia de caracteres dada é representada por uma string em código UTF-8, mas você pode supor que apenas os caracteres com sinais diacríticos usados em português aparecem na cadeia. A nova cadeia de caracteres deve ser representada por uma string ASCII.
Escreva um programa para converter notação decimal em notação hexadecimal.  O seu programa deve receber, pela linha de comando, um número em notação decimal e exibir a representação hexadecimal do número.  Repita o exercício para converter hexadecimal em decimal, decimal em octal, octal em decimal, etc.
Inteiro para string decimal.  Escreva uma função que receba um inteiro n e devolva a string ASCII de dígitos decimais que represente n da maneira usual. Por exemplo, o inteiro -123 deve ser convertido em "-123".
String decimal para inteiro.  Escreva uma função que receba uma string ASCII de dígitos decimais e devolva o correspondente número inteiro positivo. Por exemplo, ao receber a string "123", devolve o inteiro 123.  (Se a string for longa demais, descarte os últimos dígitos.)  Depois, faça uma versão mais sofisticada da função que permita que o primeiro elemento da string seja '+' ou '-'.
Inteiro para string binária.  Escreva uma função que receba um inteiro positivo n e devolva a string ASCII de 0s e 1s que represente n em notação binária. Por exemplo, o inteiro 123 deve ser convertido em "1111011".
String binária para inteiro.  Escreva uma função que receba uma string ASCII de 0s e 1s, interprete essa string como um número natural em notação binária e devolva o valor desse número. (Se a string for longa demais, descarte os últimos dígitos.) Por exemplo, a string "1111011" deve ser convertida no inteiro 123.
Ordem lexicográfica
A ordem lexicográfica entre strings (erroneamente conhecida como ordem alfabética) é análoga à ordem em que as palavras constam de um dicionário:  uma string s precede uma string t se o primeiro byte de s diferente do correspondente byte de t é menor que o byte de t.  Dizemos também que s é lexicograficamente menor que t.

Portanto, para comparar lexicograficamente duas strings s e t faça o seguinte. Procure a primeira posição, digamos k, em que as duas strings diferem. Se s[k] < t[k] então s é lexicograficamente menor que t.  Se s[k] > t[k] então s é lexicograficamente maior que t.  Se k não está definido então s e t são iguais ou uma é prefixo próprio da outra; no segundo caso, a string mais curta é lexicograficamente menor que a mais longa.

Exercícios 6
Escreva uma função que receba duas strings digamos s e t, e decida se s é lexicograficamente menor que t.
O seguinte fragmento de programa pretende decidir se abacate vem antes ou depois de banana no dicionário. O que há de errado?
char *b, *a;
a = "abacate"; b = "banana";
if (a < b) printf ("%s vem antes de %s\n", a, b);
else       printf ("%s vem depois de %s\n", a, b);
O seguinte fragmento de programa pretende decidir se abacate vem antes ou depois de amora no dicionário. O que há de errado?
char *a, *b;
a = "abacate"; b = "amora";
if (*a < *b) printf ("%s vem antes de %s\n", a, b);
else         printf ("%s vem depois de %s\n", a, b);
A biblioteca string
A biblioteca string (não confunda com a biblioteca obsoleta strings) contém várias funções de manipulação de strings.  Para usar essas funções, o seu programa deve incluir a interface string.h:

#include <string.h>
Segue uma descrição das funções mais importantes da biblioteca.

String length.  A função strlen recebe uma string e devolve o seu comprimento.  O código dessa função poderia ser escrito assim:

unsigned int strlen (char *s) {
   int k;
   for (k = 0; s[k] != '\0'; ++k) ;
   return k;
}
String copy.  A função strcpy recebe duas strings e copia a segunda (inclusive o byte nulo final) para o espaço ocupado pela primeira. O conteúdo original da primeira string é perdido. Não chame a função se o comprimento da primeira string for menor que o da segunda.  (Buffer overflow é uma das mais comuns origens de bugs de segurança!)  O código dessa função poderia ser escrito assim:

void strcpy (char *s, char *t) {
   int i;
   for (i = 0; t[i] != '\0'; ++i) 
      s[i] = t[i];
   s[i] = '\0';
}
(Na verdade, a função strcpy não é do tipo void;  ela é do tipo char* e devolve o seu primeiro argumento. Isso é útil em algumas situações, mas em geral o usuário só está interessado no efeito da função e não no que ela devolve.)

A função strcpy pode ser usada da seguinte maneira para obter um efeito semelhante ao do exemplo no início deste capítulo:

char s[10];
strcpy (s, "ABC");
String compare.  A função strcmp recebe duas strings e compara as duas lexicograficamente. Ela devolve um número estritamente negativo se a primeira string for lexicograficamente menor que a segunda, devolve 0 se as duas strings são iguais e devolve um número estritamente positivo se a primeira string for lexicograficamente maior que a segunda.  O código da função poderia ser escrito assim:

int strcmp (char *s, char *t) {
   int i;
   for (i = 0; s[i] == t[i]; ++i)
      if (s[i] == '\0') return 0;
   unsigned char si = s[i], ti = t[i];
   return si - ti;
}
(Vale lembrar que o valor da expressão  si - ti  é calculado em aritmética int, e não módulo 256.)

Se as strings s e t são ASCII, elas representam cadeias de caracteres ASCII. Nesse caso, a ordem lexicográfica entre as strings coincide com a ordem em que as cadeias apareceriam em um dicionário (pois a ordem  … 0 … 9 … A B … Z … a b … z …  em que os caracteres aparecem na tabela ASCII é consistente com a ordem alfabética usual). Por exemplo, a seguinte sequência de palavras está em ordem lexicográfica:

abacaXi
abacate
abacates
abacaxi
Se as strings não são ASCII (ou seja, se têm bytes maiores que 127), a situação é potencialmente mais complexa. Nesse caso, cada string representa uma cadeia de caracteres em código UTF-8, e portanto cada caractere é representado por 1 a 4 bytes consecutivos. Felizmente, o código UTF-8 foi construído de tal maneira que ? a ordem lexicográfica entre as strings coincide com a ordem em que as cadeias apareceriam em um dicionário se os caracteres fossem colocados em ordem crescente dos seus números Unicode, ou seja, … 0 … 9 … A B … Z … a b … z … À Á … Ç È … à á … ç è …  (veja a sequência completa na página UTF-8 encoding table and Unicode characters, por exemplo). Por exemplo, a seguinte sequência de palavras está em ordem lexicográfica:

abocanhar
abrir
abóbora
academia
acordar
acácia
adaptar
aço
açucarado
ação
(Essa ordem lexicográfica parece estranha pois deixa as letras acentuadas longe das correspondentes letras sem acentos. A propósito, veja a função strcoll num dos exercício abaixo.)

Exercícios 7
Qual a diferença entre as expressões  strcpy (s, t)  e  s = t??
Qual a diferença entre as expressões  if (strcmp (s, t) < 0)  e  if (s < t)??
Discuta as diferenças entre os três fragmentos de programa a seguir:
char a[8], b[8];
strcpy (a, "abacate"); strcpy (b, "banana");
char *a = malloc (8), *b = malloc (8); 
strcpy (a, "abacate"); strcpy (b, "banana");
char *a, *b; 
a = "abacate"; b = "banana";
Estude a documentação da função strncpy da biblioteca string.
Escreva uma função que receba uma string s e devolva uma cópia de s.  (Compare sua função com a função strdup da biblioteca string. Qual a diferença entre essa função e strcpy?)
Escreva uma função que receba uma string ASCII s e um caractere ASCII c e devolva o índice da primeira posição em s que é igual a c.  (Compare sua função com a função strchr da biblioteca string.  Agora faça uma versão mais completa da função para procurar c a partir de uma dada posição i.
Escreva uma função que receba strings x e s e devolva o índice da posição a partir da qual x ocorre em s.  (Compare sua função com a função strstr da biblioteca string.)
Escreva uma função que decida se um vetor vs[0..n-1] de strings está em ordem lexicográfica.
? Suponha dado um vetor vs[0..n-1] de strings, em ordem lexicográfica, e uma string s.  Problema: se vs não contém uma string igual a s, inserir s no vetor de modo a manter a ordem lexicográfica. Escreva uma função que resolva o problema e devolva 1 se a inserção tiver sido feita e 0 em caso contrário.
? Suponha que strings s e t representam, em código UTF-8, as cadeias de caracteres S e T respectivamente. Prove que a ordem lexicográfica entre s e t (dada por strcmp (s, t)) coincide com a ordem em que as cadeias S e T estariam num dicionário se o conjunto de caracteres estivesse em ordem crescente de números Unicode.
? Ordem lexicográfica em português.  A ordem lexicográfica calculada pela função strcmp compara duas strings byte a byte, ignorando as características do eventual esquema de codificação. Se as strings representam cadeias de caracteres em código UTF-8, a ordem lexicográfica é consistente com a ordem crescente dos números Unicode dos caracteres. Infelizmente, essa não é a ordem usual de um dicionário de português, pois as letras maiúsculas ficam longe das correspondentes minúsculas e longe das correspondentes letras com diacríticos (por exemplo, A, a e á ficam longe umas das outras). Para contornar esse inconveniente, use a variante strcoll de strcmp. ? A ordem lexicográfica calculada por strcoll (o nome da função é uma abreviatura de string collate) usa a ordenação dos caracteres determinada pela variável de ambiente LC_COLLATE do seu sistema. Se o valor de LC_COLLATE é pt_BR.UTF-8, por exemplo, a ordem dos caracteres é  … a A á Á à À â Â … b B c C ç Ç d D … z Z …
Use a função strcoll para escrever um programa que ordene lexicograficamente uma sequência de palavras em português codificada em UTF-8. As palavras são digitadas no terminal e a lista ordenada deve ser exibida na tela, uma por linha. Faça testes. Se o valor de LC_COLLATE no seu sistema não for pt_BR.UTF-8, você pode fazer algo assim:

#include <locale.h>
void main (void) {
   setlocale (LC_COLLATE, "pt_BR.UTF-8");
   ... código da ordenação ...
}
Veja a biblioteca strlib de Eric Roberts
Veja os verbetes C string handling e Null-terminated string na Wikipedia
Veja o artigo On Character Strings de Tim Bray
Atualizado em 2018-05-09
https://www.ime.usp.br/~pf/algoritmos/
Paulo Feofiloff
DCC-IME-USP

 Valid CSS!  Valid HTML 4.01 Strict
