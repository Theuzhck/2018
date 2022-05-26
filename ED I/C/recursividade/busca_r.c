int main(){
    int x, k, n = 5, lim ;
    int v[n];
    int *pv;

    pv = (int *)malloc(n * sizeof(int));
    for (k = 0; k < n; ++k){
        v[k] = rand() % lim;
        printf("Posicao %d com valor: %d\n",k , v[k]);
    }
    x = rand() % lim;
    printf("Numero a ser pesquisado: %d\n", x);
    free(pv);

    printf("Posicao de %d no vetor: %d.\n", x, busca_r(x, n, v));
    system("pause");
    return 0;
}

int busca_r(int x, int n, int v[]){
    if (n == 0) return -1;
    if (x == v[n - 1]) return n - 1;
    return busca_r(x, n-1, v);

}
