int main(){
    int n;
    scanf("%i", &n);

    naturais(n);

    system("pause");
    return 0;
}

int naturais(int n){
    int res;
    if (n > 0){
        printf("%i\n", n);
        res = (1 - naturais(n - 1));
    }else if (n == 0){
        printf("%i\n", n);
    }
    return res;
}

