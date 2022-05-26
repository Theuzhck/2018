int main(){
    int x, y;
    scanf ("%i", &x);
    scanf ("%i", &y);

    printf("%i", mdc(x, y));

    system("pause");
    return 0;
}

int mdc(int x, int y){
    if (y == 0)
        return x;
    else{
        return mdc(y, x % y);
    }
}
