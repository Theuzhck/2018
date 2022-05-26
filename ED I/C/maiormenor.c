int main(){
    int n1, n2, n3, n4, n5, n6;


    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    scanf("%d", &n4);
    scanf("%d", &n5);
    scanf("%d", &n6);

    int v[6] = {n1, n2, n3, n4, n5, n6};
    printf("%d\n", menor(v));
    printf("%d", maior(v));


    system("pause");
    return 0;
}

int maior(int v[]){
    int mais = 0, i;

    for (i = 0; i <= 5; ++i){
        if (v[i] > mais){
            mais = v[i];
        }
    }
    return mais;
}

int menor(int v[]){
    int menos = 9999999, i;

    for (i = 0; i <= 5; ++i){
        if (v[i] < menos){
            menos = v[i];
        }
    }
    return menos;
}
