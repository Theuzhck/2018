int main(){
    int n;
    scanf("%i", &n);

    printf("%i\n", fatorial(n));

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
