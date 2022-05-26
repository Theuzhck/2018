  struct reg {
      int         conteudo; 
      struct reg *prox;
   };
   
    typedef struct reg celula;
    
    void imprime (celula *le) {
   if (le != NULL) {
      printf ("%d\n", le->conteudo);
      imprime (le->prox);
   }
}

// Esta função recebe um inteiro x e uma 
// lista encadeada le de inteiros e devolve
// o endereço de uma celula que contém x. 
// Se tal célula não existe, devolve NULL.

celula *
busca (int x, celula *le)
{
   celula *p;
   p = le;
   while (p != NULL && p->conteudo != x) 
      p = p->prox; 
   return p; 
}

//Uma lista encadeada le com cabeça está vazia se e somente se le->prox == NULL.  Para criar uma lista encadeada vazia com cabeça, basta dizer

   celula *le;
   le = malloc (sizeof (celula));
   le->prox = NULL;
//Para imprimir o conteúdo de uma lista encadeada le com cabeça, faça

void imprima (celula *le) {
   celula *p;
   for (p = le->prox; p != NULL; p = p->prox) 
      printf ("%d\n", p->conteudo);
}

// Esta função insere uma nova celula
// em uma lista encadeada. A nova celula
// tem conteudo x e é inserida entre a
// celula p e a célula seguinte.
// (Supõe-se que p != NULL.)

void 
insere (int x, celula *p)
{
   celula *nova;
   nova = mallocc (sizeof (celula));
   nova->conteudo = x;
   nova->prox = p->prox;
   p->prox = nova;
}

// Esta função recebe o endereço p de uma 
// celula de uma lista encadeada e remove 
// da lista a celula p->prox. A função supõe 
// que p != NULL e p->prox != NULL.

void 
remove (celula *p)
{
   celula *lixo;
   lixo = p->prox;
   p->prox = lixo->prox;
   free (lixo);
}

// Esta função recebe uma lista encadeada le
// com cabeça e remove da lista a primeira
// celula que contiver y, se tal celula existir.

void 
busca_e_remove (int y, celula *le)
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
   }
}

// Esta função recebe uma lista encadeada le
// com cabeça e insere na lista uma nova celula
// imediatamente antes da primeira que contém y.
// Se nenhuma celula contém y, insere a nova
// celula no fim da lista. O conteudo da nova
// celula é x.

void 
busca_e_insere (int x, int y, celula *le)
{
   celula *p, *q, *nova;
   nova = mallocc (sizeof (celula));
   nova->conteudo = x;
   p = le;
   q = le->prox;
   while (q != NULL && q->conteudo != y) {
      p = q;
      q = q->prox;
   }
   nova->prox = q;
   p->prox = nova;
}
  
