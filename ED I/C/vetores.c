// A função recebe x, n >= 0 e v e devolve
// um índice k em 0..n-1 tal que x == v[k]. 
// Se tal k não existe, devolve -1.

int
busca (int x, int n, int v[])
{
   int k;
   k = n-1;
   while (k >= 0 && v[k] != x) 
      k -= 1;
   return k;
}

// Recebe x, n >= 0 e v e devolve k
// tal que 0 <= k < n e v[k] == x. 
// Se tal k não existe, devolve -1

int busca_r (int x, int n, int v[]) {
   if (n == 0) return -1;
   if (x == v[n-1]) return n-1;
   return busca_r (x, n-1, v);
}

// Esta função recebe um vetor v[0..n-1]
// e um índice k tal que 0 <= k < n.
// Ela devolve v[k] e remove esse
// elemento do vetor.

int
remove (int k, int n, int v[])
{
   int x = v[k];
   for (int j = k+1; j < n; ++j)  
      v[j-1] = v[j];
   return x;
}

// Esta função recebe um vetor v[0..n-1]
// e um índice k tal que 0 <= k < n.
// Ela devolve v[k] e remove esse
// elemento do vetor.

int remove_r (int k, int n, int v[]) {
   int x = v[k];
   if (k < n-1) {
      int y = remove_r (k+1, n, v); 
      v[k] = y;
   }
   return x;
}

// Esta função insere x entre v[k-1]
// e v[k] no vetor v[0..n-1] para
// qualquer k tal que 0 <= k <= n.

void
insere (int k, int x, int n, int v[])
{
   for (int j = n; j > k; --j)  
      v[j] = v[j-1];
   v[k] = x;
} 

// Esta função insere x entre v[k-1]
// e v[k] no vetor v[0..n-1] para
// qualquer k tal que 0 <= k <= n.

void insere_r (int k, int x, int n, int v[]) {
   if (k == n)  v[n] = x;
   else {
      v[n] = v[n-1];
      insere_r (k, x, n - 1, v);
   }
}

// Esta função elimina todos os
// elementos nulos de v[0..n-1].
// Supõe apenas que n >= 0. A função
// deixa o resultado em v[0..i-1]
// e devolve i.
    
int
tirazeros (int n, int v[])
{
   int i = 0;
   for (int j = 0; j < n; ++j)  
      if (v[j] != 0) 
         v[i++] = v[j];
   return i;
}

// A função tirazeros_r elimina todos
// os elementos nulos de v[0..n-1].
// A função deixa o resultado em 
// v[0..i-1] e devolve i.
    
int tirazeros_r (int n, int v[]) {
   if (n == 0) return 0;
   int m = tirazeros_r (n - 1, v);
   if (v[n-1] == 0) return m;
   v[m] = v[n-1];
   return m + 1;
}
