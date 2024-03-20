#include<stdio.h>
int fact(int x){
    if(x==1 || x==0 || x<0) return 1;
    else return x*fact(x-1);
}
int main(){
    int n;
    printf("Enter value of n: ");
    scanf("%d",&n);
    int ans = fact(n);
    printf("Factorial of %d is %d ",n,ans);



    return 0;
}