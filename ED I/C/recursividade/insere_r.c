// Esta função recebe um vetor v[0..n-1],
// um índice k tal que 0 <= k < n e
// uma valor x para ser adicionado em v
// Ela devolve v[n] e insere x entre a
// posicao k e k+1.
void insere_rz (int k, int x, int n, int v[]) {
   if (k == n)  v[n] = x;
   else {
      v[n] = v[n-1];
      insere_rz (k, x, n - 1, v);
   }
}

int main(){
    int n, a, z, k, x;
    n = 10;
    a = 2;
    z = 8;
    k = 5;
    x = 20;

    int v[] = {0,1,2,3,4,5,6,7,8,9};

    insere_rz(k,x,n,v);
    ++n;
    for (int i = 0; i < n; i++)
        printf("Valores: %d\n", v[i]);
}
