#include<stdio.h>
int remaind(int a, int b ,int m){
    if(b==0) return 1;
    if(b==1) return a%m;
    if(b%2!=0){
        int temp;
        temp=remaind(a,b/2,m);
        
        return (temp*temp*(a%m))%m;
    }
    if(b%2==0){
        int temp=remaind(a,b/2,m);

        return (temp*temp)%m;
    }

}
int main(){
    int a,b,m;
    printf("Enter a b and c : ");
    scanf("%d%d%d",&a,&b,&m);
    int ans=remaind(a,b,m);
    printf("Remainder is %d ",ans);


    return 0;
}
