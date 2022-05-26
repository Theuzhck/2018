#include <stdio.h>
#include <string.h>
// A função tirachar elimina todos os
// elementos y de v[0..n-1].
// A função deixa o resultado em
// v[0..i-1] e devolve m + 1.

int tirachar (int n, char v[], char y) {
   if (n == 0) return 0;
   int m = tirachar (n - 1, v, y);
   if (v[n-1] == y) return m;
   v[m] = v[n-1];
   return m + 1;
}

int main(){
    int n = 10;
    char v[] = {'a', 'b', 'c', 'd', 'a', '#','#','#','#'};;
    char y = '#';

    for(int i=0; i < n; ++i)
        printf("%c\n", v[i]);
    printf("______________________________\n");

    n = tirachar (n, v, y);

    for(int i=0; i < n; ++i)
        printf("%c\n", v[i]);
    return 0;
}
