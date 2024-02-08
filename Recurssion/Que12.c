#include<stdio.h>

int sum(int x){
    if(x%10==x) return x;
    return (x%10)+sum(x/10);
}
int main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int ans=sum(n);
    printf("Sum of the digit is : %d ",ans);


    return 0;
}