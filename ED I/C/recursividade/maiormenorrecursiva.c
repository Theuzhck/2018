int main(){
    int n, j;

    n = 6;

    int v1[n];


    for (j = 0; j < n; ++j){
        int temp;
        scanf("%d", &temp);
        v1[j] = temp;
    }



    printf("%d\n", maior(v1, n));
    printf("%d\n", menor(v1, n));

    system("pause");
    return 0;
}

int maior(int *v, int n){

    if (n == 0)
        return 0;
	else if (v[n - 1] > maior(v, n - 1))
        return (v[n - 1]);
	else
        return maior(v, n - 1);

}

int menor(int *v, int n){

    if (n == 0)
        return v[n];
	else if (v[n - 1] < menor(v, n - 1))
        return (v[n - 1]);
	else
        return menor(v, n - 1);

}
