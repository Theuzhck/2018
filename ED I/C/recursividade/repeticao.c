#include <stdio.h>

int main(){
    int k, n, cont;
    scanf("%i %i", &k, &n);

    printf ("%i\n", repete(k, n, 0));

    system("pause");
    return 0;
}

int repete(int k, int n, int cont){
    int resto;

    do{
        resto = n % 10;
        n = n/10;
        if (resto == k){
            cont = cont + 1;
            repete(k, n, cont);
        } else if ((resto == 0) && (n == 0)){
            break;
        }
        else
            repete(k, n, cont);
    }
    while (n > 0 );
    return cont;
}
