int main(){
    int n, i;

    scanf("%i", &n);

    int v1[n], v2[n];

    for (i = 0; i < n; ++i){
        int temp;
        scanf("%i", &temp);
        v1[i] = temp;
    }

    for (i = 0; i < n; ++i){
        int temp;
        scanf("%i", &temp);
        v2[i] = temp;
    }
    print(v1, v2, n);

    system("pause");
    return 0;
}

int print (int *v1, int *v2, int n){
    int cont;
    for (cont = 0; cont < n; ++cont){
        printf("%d\n", v1[cont]);
        printf("%d\n", v2[cont]);
    }
    return 0;
}
