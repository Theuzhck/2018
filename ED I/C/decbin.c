int main(){
    int x;
    char y;
    scanf ("%i %c", &x, &y);

    printf("%c %d", y, x);

    system("pause");
    return 0;
}

int dec(int x){
    if ((x == 0) || (x == 1) ){
        printf("%d\n", x%2);
    }else{
        dec(x/2);
        printf("%d\n", x%2);
    }
}
