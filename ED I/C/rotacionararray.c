#include <stdlib.h>
int main(){
    int n, j, i, k;

    scanf("%d", &n);

    int v1[n];
    int res[n];

    for (k = 0; k < n; k++) res[k] = 0;

    for (j = 0; j < n; ++j){
        int temp;
        scanf("%d", &temp);
        v1[j] = temp;
    }

    scanf("%d", &i);

    rotacionar(v1, i, n, res);

    system("pause");
    return 0;
}

int rotacionar(int *v, int i, int n, int *res){
    int k, temp;
    int *pv;

    if (i == 0){
        return v;
    }else{
        pv = (int *)malloc(n * sizeof(int));
        for (k = 0; k < n; ++k){
            temp = i + k;
            if (temp >= n){
                temp = temp - n;
            }
            res[k] = v[temp];
            printf("%d\n", res[k]);
        }
        free(pv);
    }

    return 0;
}
