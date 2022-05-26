int main(){
    int n1, n2;
    printf("Digite dois numeros:\n");
    scanf("%i", &n1);
    scanf("%i", &n2);

    if (n2 == 0){
        printf("Nao e permitida divisao por 0.\n");
    } else if ((n1 % n2) == 0){
        printf("O num %i e divisivel por %i\n", n1, n2);
    } else{
        printf("O num %i nao e divisivel por %i\n", n1, n2);
    }

    system("pause");
    return 0;
}
