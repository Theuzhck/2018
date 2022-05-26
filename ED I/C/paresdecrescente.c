int main(){
    int n;
    scanf("%i", &n);

    paresdecrescente(n);

    system("pause");
    return 0;
}

int paresdecrescente(int n){
    int res;

    if (n > 0){
        if (n % 2 == 0){
            printf("%i\n", n);
        }
        paresdecrescente(n - 1);
    }else if (n == 0){
        printf("%i\n", n);
    }
    return res;
}


