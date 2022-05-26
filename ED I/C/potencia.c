int main(){
    int base, exp, res;

    scanf("%i", &base);
    scanf("%i", &exp);
    res = potencia(base, exp);

    printf ("Resultado: %i\n", res);

    system("pause");
    return 0;
}

int potencia(int base, int exp){
    if (exp == 0){
        return 1;
    } else{
        return (base * potencia(base, (exp - 1)));
    }

}
