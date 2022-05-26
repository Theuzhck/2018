int main(){
    int n, cima, baixo;
    float res;
    scanf("%i", &n);

    cima = fatorial(2 * n);
    baixo = fatorial(n);
    res = cima / baixo;

    printf("%f\n", res);

    system("pause");
    return 0;
}

int fatorial(int n){
    if (n == 0)
        return 0;
    else if(n == 1){
        return 1;
    }else{
        return(n * (fatorial(n - 1)));
    }
}
