#include<stdio.h>
// solve nhi hua hai abhi.....
int main(){
    int n1,n2;
    scanf("%d",&n1);
    int a[n1];
    for(int i=0;i<n1;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&n2);
    int b[n2];
    for(int i=0;i<n2;i++){
        scanf("%d",&b[i]);
    }
    int c[n1+n2];
    int k1=0,k2=0,p,buff;
    int min;
    if(n1<n2) min=n2;
    else min=n2;
    

    for(int i=0;i<n1+n2;i++){
        
        if(k1<n1 && k2<n2){
        if(a[k1]<b[k2]){
            p=a[k1];
            k1+=1;
        }
        else if(b[k2]<a[k1]){
            p=b[k2];
            k2+=1;
        }
        else buff=1;
        }
        else{
            if(min==n1){
                p=b[k2];
                k2+=1;
            }
            if(min==n2){
                p=a[k1];
                k1+=1;
            }
        }
        
        
        
        
       //printf("%d %d   ",k1,k2);
        c[i]=p;
    }
    for(int i=0;i<n1+n2;i++){
        printf("%d  ",c[i]);
    }





    return 0;
}