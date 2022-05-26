int main(){
    int cont;
    printf("Digite um numero: \n");
    scanf("%i", &cont);

    /*int i;
    for(i = 0; i <= cont; ++i){
        if ((i%2)==0){
            printf("%i\n", i);
        }
    }*/
    int v = vetorial(cont);
    printf("%i\n", v);

    system("pause");
    return 0;
}

int vetorial(int n){
    if (n == 0){
        return 1;
    }else if (n == 1){
        return 1;
    }else{
        return (n * (vetorial (n - 1)));
    }
}
