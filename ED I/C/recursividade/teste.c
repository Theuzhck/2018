void insere_ra (int k, int x, int n, int v[]) {
    int aux = v[k];
   if ()  v[n] = x;
   else {
      insere_ra (k, aux, n - 1, v);
   }
}

int main(){
    int n, a, z, k, x;
    n = 10;
    a = 2;
    z = 8;
    k = 3;
    x = 20;

    int v[] = {0,1,2,3,4,5,6,7,8,9};

    insere_ra(k,x,n,v);
    ++n;
    for (int i = 0; i < n; i++)
        printf("Valores: %d\n", v[i]);
}
