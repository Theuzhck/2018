int main(){
    int n1, n2;
    scanf("%i %i", &n1, &n2);

    printf("%i\n", multisoma(n1, n2));

    system("pause");
    return 0;
}

int multisoma(int n1, int n2){
    if (n2 == 1){
        return n1;
    }else{
        return (n1 + (multisoma(n1, n2 - 1)));
    }
}
