#include<stdio.h>

int num(int x){
    if(x==1) {
        printf("%d ,",x);
    }
    else printf("%d ,",1+())
    
    num(x-1);
    printf("%d ,",x);

    return 0;
}


int main(){
    int n;
    printf("Enter value of n: ");
    scanf("%d",&n);
    num(n);

    return 0;
}