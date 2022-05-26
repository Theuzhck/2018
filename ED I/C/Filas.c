// fila em vetor
int tiradafila (void) {
   return fila[p++];
}

void colocanafila (int y) {
   fila[u++] = y;
}

#define N 100
int fila[N], int p, u;
int dist[N];

void criafila (void) {
   p = 0; u = 0;
}

int filavazia (void) {
   return p >= u;
}

int tiradafila (void) {
   return fila[p++];
}

void colocanafila (int y) {
   fila[u++] = y;
}

// Esta função recebe uma matriz A
// que representa as interligações entre
// cidades 0..N-1 e preenche o vetor dist
// de modo que dist[i] seja a distância
// da cidade c à cidade i, para cada i.

void distancias (int A[][N], int c) {
   for (int j = 0; j < N; ++j)  dist[j] = N;
   dist[c] = 0;
   criafila ();
   colocanafila (c);

   while (!filavazia ()) { 
      int i = tiradafila ();
      for (int j = 0; j < N; ++j)
         if (A[i][j] == 1 && dist[j] >= N) {
            dist[j] = dist[i] + 1;
            colocanafila (j);
         }
   }
}

// FILA EM LISTA ENCADEADA
typedef struct reg {
   int         conteudo; 
   struct reg *prox;
} celula;

// Tira um elemento da fila fi e devolve
// o conteudo do elemento removido.
// Supõe que a fila não está vazia.

int tiradafila (celula *fi) {
   celula *p;
   p = fi->prox;  // o primeiro da fila
   int x = p->conteudo;
   fi->prox = p->prox;
   free (p);
   return x;  
}

// Coloca um novo elemento com conteudo y
// na fila fi. Devolve o endereço da
// cabeça da fila resultante.

celula *colocanafila (int y, celula *fi) { 
   celula *nova;
   nova = mallocc (sizeof (celula));
   nova->prox = fi->prox;
   fi->prox = nova;
   fi->conteudo = y;
   return nova;
}
