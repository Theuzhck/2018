#include <stdlib.h>
int main(){
    int n, j, i;

    //scanf("%d", &n);
    //scanf("%d", &i);
    n = 6;
    i = 3;

    int v1[6] = {1, 2, 3, 4, 5, 6};
    int res[6];

    /*
    for (j = 0; j < n; ++j){
        int temp;
        scanf("%d", &temp);
        v1[j] = temp;
    }*/
    inverter(v1, res, n);

    system("pause");
    return 0;
}

int inverter(int *v, int *res, int n){
    int k, aux;
    int *pv;

    pv = (int *)malloc(n * sizeof(int));
    for (k = 0; k < n/2; k++) {
        aux = v[k];
        v[k] = v[n-1-k];
        v[n-1-k] = aux;
    }

    for (k = 0; k < n; k++)
        printf("%d\n", v[k]);

    //free(pv);

    return 0;
}
