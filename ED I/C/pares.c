int main(){
    int cont;
    scanf("%i", &cont);
    pares(cont);

    system("pause");
    return 0;
}

int pares (int n){
  if (n == 0) {
    printf("%i\n", 0);
  }
  else if (n < 0){
      if (n % 2 == 0){
        printf("%i\n", n);
      }
      pares(n + 1);
  }
  else if (n >= 0){
      pares(n - 1);
      if (n % 2 == 0){
        printf("%i\n", n);
      }
    }
}
