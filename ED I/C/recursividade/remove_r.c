int remove_rz(int k, int n, int a, int z, int v[]){

    if (z > n) return -1;
    if (a == z-1) return 0;
    int x = v[k];
    if (k > a && k < z){
        int y = remove_rz(k+1, n, a, z, v);
        v[k] = y;
    }

    return x;
}

int remove_ra(int k, int n, int a, int z, int v[]){

    if (z > n) return -1;
    if (a == z-1) return 0;
    int x = v[k];
    if (k > a && k < z){
        int y = remove_ra(k-1, n, a, z, v);
        v[k] = y;
    }
    return x;
}

int main(){
    int n, a, z, k;
    n = 10;
    a = 2;
    z = 8;
    k = 3;

    int v[] = {0,1,2,3,4,5,6,7,8,9};

    if (k-a < z-k){
        remove_ra(k,n,a,z,v);
        n = n - 1;
        for (int i=0; i<n;i++)
            printf("valores sendo mais proximo de A: %d\n", v[i]);
        printf("valor de n: %d", n);
    }else{
        remove_rz(k,n,a,z,v);
        n = n - 1;
        for (int i=0; i<n;i++)
            printf("valores sendo mais proximo de Z: %d\n", v[i]);
        printf("valor de n: %d", n);
        }
}
