// fibbonaci
int fibo(int x){
    if(x==1 || x==0) return 1;
    return fibo(x-1)+fibo(x-2);
}