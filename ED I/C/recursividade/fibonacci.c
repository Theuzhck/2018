int main(){
    int n;
    scanf("%i", &n);

    printf("%i\n", fibonacci(n));

    system("pause");
    return 0;
}

int fibonacci(int n){
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else{
        return (fibonacci(n-1) + fibonacci(n-2));
    }

}
