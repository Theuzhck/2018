int main(){
    int n1;
    scanf("%i", &n1);

    int resto;
    int resultado;

    resto = (n1 % 10);
    resultado = n1 / 10;
    printf("%i", resto);

    do{
        resto = resultado % 10;
        resultado = resultado / 10;
        printf("%i", resto);
    }
    while (resultado > 0 );
    printf("\n");

    system("pause");
    return 0;
}
