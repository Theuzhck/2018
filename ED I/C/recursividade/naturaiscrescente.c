int main(){
    int n;
    //scanf("%i", &n);
    n = 10;

    naturais(n);

    system("pause");
    return 0;
}

int naturais(int n){
    int res;
    if (n == 0)
        printf("%i\n", n);
    else{
        res = (1 + naturais(n - 1));
        printf("%i\n", n);
    }
    return res;
}
