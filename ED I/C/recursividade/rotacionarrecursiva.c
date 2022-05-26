#include <stdlib.h>

int main(){
    int n, j, i, k, l;

    //scanf("%d", &n);
    n = 6;
    int v1[6] = {1, 2, 3, 4, 5, 6};
    int res[n];
    /*
    for (k = 0; k < n; k++) res[k] = 0;

    for (j = 0; j < n; ++j){
        int temp;
        scanf("%d", &temp);
        v1[j] = temp;
    }*/

    //scanf("%d", &i);
    i = 2;

    rotacionar(v1, i, n);

    for (k = 0; k < n; ++k)
        printf("%d\n", res[k]);
    /*
    for (l = 0; l < n; ++l){
        printf("%d\n", res[l]);
    }*/


    system("pause");
    return 0;
}

int rotacionar(int *v, int i, int n){
    int k, temp, j;
    int *pv;
    int res[n];

    if (n == 1)
        return v;
    else{
        rotacionar(v, i, n-1);
        pv = (int *)malloc(n * sizeof(int));
        for (k = 0; k < n; k++) res[k] = 0;
        for (k = 0; k < n; ++k){
            temp = i + k;
            if (temp >= n)
                temp = temp - n;
            res[k] = v[temp];
        }

        free(pv);


    }
    return res;
}
