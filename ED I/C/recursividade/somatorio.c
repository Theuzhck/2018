int main(){
    int n;
    scanf("%i", &n);

    printf("%i\n", somatorio(n));

    system("pause");
    return 0;
}

int somatorio(int n){
    if (n == 0)
        return 0;
    else{
        return (n + (somatorio(n - 1)));
    }
}
